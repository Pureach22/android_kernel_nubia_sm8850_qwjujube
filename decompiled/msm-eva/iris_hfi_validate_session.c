__int64 __fastcall iris_hfi_validate_session(_QWORD *a1)
{
  _QWORD *v2; // x20
  _QWORD *v3; // x8
  unsigned int v4; // w22
  unsigned __int64 v5; // x8
  unsigned __int64 StatusReg; // x8

  if ( a1 && (v2 = (_QWORD *)a1[4]) != nullptr )
  {
    mutex_lock(v2 + 10);
    v3 = v2;
    while ( 1 )
    {
      v3 = (_QWORD *)*v3;
      if ( v3 == v2 )
        break;
      if ( v3 == a1 )
      {
        v4 = 0;
        goto LABEL_13;
      }
    }
    v4 = -104;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_963E0, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    }
LABEL_13:
    mutex_unlock(v2 + 10);
  }
  else
  {
    v4 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v5 = _ReadStatusReg(SP_EL0);
      printk(&unk_94F15, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), &unk_8E7CE);
    }
  }
  return v4;
}
