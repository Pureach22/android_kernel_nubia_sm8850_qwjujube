__int64 __fastcall dbglog_report_enable(__int64 a1)
{
  _ReadStatusReg(SP_EL0);
  wma_config_debug_module_cmd(a1);
  wma_config_debug_module_cmd(a1);
  _ReadStatusReg(SP_EL0);
  return 0;
}
