_QWORD *__fastcall _session_clean(_QWORD *result, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *v4; // x20
  _QWORD *v5; // x8
  _QWORD *v6; // x8
  __int64 v7; // x9
  _QWORD *v8; // x19
  unsigned __int64 StatusReg; // x8
  _QWORD *v10; // x9

  v4 = (_QWORD *)result[4];
  if ( v4 )
  {
    if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
    {
      v8 = result;
      printk(&unk_8F444, "sess", result, a4);
      result = v8;
    }
    v5 = v4;
    while ( 1 )
    {
      v5 = (_QWORD *)*v5;
      if ( v5 == v4 )
        break;
      if ( v5 == result )
      {
        v6 = (_QWORD *)result[1];
        if ( (_QWORD *)*v6 == result && (v7 = *result, *(_QWORD **)(*result + 8LL) == result) )
        {
          *(_QWORD *)(v7 + 8) = v6;
          *v6 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(result);
          result = v10;
        }
        break;
      }
    }
    result[3] = 0;
    result[4] = 0;
    result[1] = 0;
    result[2] = 0;
    *result = 0;
    return (_QWORD *)kfree(result);
  }
  else if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    return (_QWORD *)printk(
                       &unk_912BD,
                       *(unsigned int *)(StatusReg + 1800),
                       *(unsigned int *)(StatusReg + 1804),
                       "warn");
  }
  return result;
}
