__int64 __fastcall cnss_put_vreg_type(
        __int64 result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v8; // w29
  __int64 *v9; // x19
  _QWORD *v10; // x20
  _QWORD **v11; // x23
  unsigned __int64 StatusReg; // x28
  _QWORD *v13; // x8
  __int64 v14; // x9
  unsigned __int64 v15; // x8
  __int64 v16; // x26
  const char *v17; // x1
  char v18; // [xsp+0h] [xbp-60h]

  if ( !a2 )
  {
    v18 = v8;
    v9 = (__int64 *)result;
    v11 = (_QWORD **)(result + 24);
    v10 = *(_QWORD **)(result + 24);
    if ( v10 != (_QWORD *)(result + 24) )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      do
      {
        v13 = (_QWORD *)v10[1];
        if ( (_QWORD *)*v13 == v10 && (v14 = *v10, *(_QWORD **)(*v10 + 8LL) == v10) )
        {
          *(_QWORD *)(v14 + 8) = v13;
          *v13 = v14;
        }
        else
        {
          result = _list_del_entry_valid_or_report(v10);
        }
        v15 = v10[2];
        *v10 = 0xDEAD000000000100LL;
        v10[1] = 0xDEAD000000000122LL;
        if ( v15 && v15 <= 0xFFFFFFFFFFFFF000LL )
        {
          v16 = *v9;
          v17 = "irq";
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
          {
            if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              v17 = "soft_irq";
            else
              v17 = (const char *)(StatusReg + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v17,
            "cnss_put_vreg_single",
            7u,
            7u,
            "Put regulator: %s\n",
            v10[3],
            a8,
            v18);
          devm_regulator_put(v10[2]);
          result = devm_kfree(v16 + 16, v10);
        }
        v10 = *v11;
      }
      while ( *v11 != v11 );
    }
  }
  return result;
}
