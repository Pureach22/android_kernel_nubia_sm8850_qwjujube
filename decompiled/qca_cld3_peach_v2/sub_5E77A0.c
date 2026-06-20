__int64 sub_5E77A0()
{
  __asm { STGP            X19, X6, [X29,#4]! }
  return wmi_unified_conf_hw_filter_cmd();
}
