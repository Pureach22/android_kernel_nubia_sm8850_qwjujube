__int64 __fastcall wma_config_debug_module_cmd(__int64 a1)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  result = wmi_unified_dbglog_cmd_send(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
