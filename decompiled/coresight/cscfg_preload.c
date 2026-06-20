__int64 __fastcall cscfg_preload(__int64 a1)
{
  qword_11948 = a1;
  return cscfg_load_config_sets(&preload_cfgs, &preload_feats);
}
