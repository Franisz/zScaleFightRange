// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  bool oCNpc::ShouldScaleFightRange( float lengthScale ) {
    if ( lengthScale == 1.0f )
      return false;

    if ( lengthScale < 1.0f && !Options::ScaleSmallerNpcs )
      return false;

    if ( lengthScale > 1.0f && !Options::ScaleLargerNpcs )
      return false;

    if ( this == player && !Options::ScalePlayer )
      return false;

    return true;
  }

  void oCNpc::ResetFightRange( float scale ) {
    if ( scale == 0.0f )
      return;

#if ENGINE >= Engine_G2
    if ( fightRangeG ) {
      int defaultRange = fightRangeG / scale + 0.5f;
      SetFightRangeG( defaultRange );
    }
#endif

    if ( fightRangeBase ) {
      int defaultRange = fightRangeBase / scale + 0.5f;
      SetFightRangeBase( defaultRange );
    }

    if ( fightRangeFist ) {
      int defaultRange = fightRangeFist / scale + 0.5f;
      SetFightRangeFist( defaultRange );
    }
  }

  HOOK Hook_oCNpc_SetModelScale PATCH( &oCNpc::SetModelScale, &oCNpc::SetModelScale_Union );
  void oCNpc::SetModelScale_Union( zVEC3 const& scale ) {
    float lengthScale_Old = (model_scale[2]) ? model_scale[2] : 0.0f;

    THISCALL( Hook_oCNpc_SetModelScale )(scale);

    ResetFightRange( lengthScale_Old );
  }

  HOOK Hook_oCNpc_SetFightRangeBase PATCH( &oCNpc::SetFightRangeBase, &oCNpc::SetFightRangeBase_Union );
  void oCNpc::SetFightRangeBase_Union( int range ) {
    float lengthScale = model_scale[2];

    if ( ShouldScaleFightRange( lengthScale ) )
      range = range * lengthScale + 0.5f;

    THISCALL( Hook_oCNpc_SetFightRangeBase )(range);
  }

  HOOK Hook_oCNpc_SetFightRangeFist PATCH( &oCNpc::SetFightRangeFist, &oCNpc::SetFightRangeFist_Union );
  void oCNpc::SetFightRangeFist_Union( int range ) {
    float lengthScale = model_scale[2];

    if ( ShouldScaleFightRange( lengthScale ) )
      range = range * lengthScale + 0.5f;

    THISCALL( Hook_oCNpc_SetFightRangeFist )(range);
  }

#if ENGINE >= Engine_G2
  HOOK Hook_oCNpc_SetFightRangeG PATCH( &oCNpc::SetFightRangeG, &oCNpc::SetFightRangeG_Union );
  void oCNpc::SetFightRangeG_Union( int range ) {
    float lengthScale = model_scale[2];

    if ( ShouldScaleFightRange( lengthScale ) )
      range = range * lengthScale + 0.5f;

    THISCALL( Hook_oCNpc_SetFightRangeG )(range);
  }
#endif
}