// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
#define PLUGIN_NAME "ZSCALEFIGHTRANGE"

  namespace Options {
    bool ScaleSmallerNpcs, ScaleLargerNpcs, ScalePlayer;

    void ReadOptions() {
      ScaleSmallerNpcs = zoptions->ReadBool( PLUGIN_NAME, "ScaleSmallerNpcs", true );
      ScaleLargerNpcs = zoptions->ReadBool( PLUGIN_NAME, "ScaleLargerNpcs", true );
      ScalePlayer = zoptions->ReadBool( PLUGIN_NAME, "ScalePlayer", true );
    }
  }
}