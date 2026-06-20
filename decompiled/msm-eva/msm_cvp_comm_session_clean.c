__int64 __fastcall msm_cvp_comm_session_clean(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 (__fastcall *v5)(_QWORD); // x9
  __int64 v6; // x0
  int v7; // w0
  unsigned __int64 v8; // x8
  unsigned __int64 StatusReg; // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 128);
    if ( v1 )
    {
      if ( *(_QWORD *)(v1 + 256) )
      {
        v2 = result;
        mutex_lock(result + 80);
        v3 = v2;
        if ( !*(_QWORD *)(v2 + 320) )
        {
          if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_946A9, "sess", "msm_cvp_comm_session_clean", v2);
            v3 = v2;
          }
          return mutex_unlock(v3 + 80);
        }
        v4 = *(_QWORD *)(*(_QWORD *)(v2 + 128) + 256LL);
        if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_8290F, "sess", "msm_cvp_comm_session_clean", v2);
          v3 = v2;
          if ( v4 )
          {
LABEL_8:
            v5 = *(__int64 (__fastcall **)(_QWORD))(v4 + 128);
            if ( v5 )
            {
              v6 = *(_QWORD *)(v3 + 320);
              if ( *((_DWORD *)v5 - 1) != -1066802076 )
                __break(0x8229u);
              v7 = v5(v6);
              v3 = v2;
              if ( v7 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                StatusReg = _ReadStatusReg(SP_EL0);
                printk(&unk_8EE3A, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
                v3 = v2;
              }
            }
          }
        }
        else if ( v4 )
        {
          goto LABEL_8;
        }
        *(_QWORD *)(v3 + 320) = 0;
        return mutex_unlock(v3 + 80);
      }
    }
  }
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v8 = _ReadStatusReg(SP_EL0);
    return printk(&unk_86F4F, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
  }
  return result;
}
