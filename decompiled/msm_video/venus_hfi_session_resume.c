__int64 __fastcall venus_hfi_session_resume(__int64 a1, unsigned int a2, int a3)
{
  __int64 result; // x0
  __int64 v4; // x19
  int hfi_port; // w0
  __int64 v6; // x21
  unsigned int v7; // w20
  int v8; // w22
  int v9; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a3;
  if ( a2 < 2 )
  {
    v4 = a1;
    hfi_port = get_hfi_port(a1, a2);
    v6 = *(_QWORD *)(v4 + 320);
    v7 = *(_DWORD *)(v4 + 332);
    v8 = hfi_port;
    core_lock(v6);
    LODWORD(v4) = venus_hfi_session_command_locked(
                    v4,
                    0x1000008u,
                    3,
                    v8,
                    v7,
                    1,
                    &v9,
                    4u,
                    (__int64)"venus_hfi_session_resume");
    core_unlock(v6);
    result = (unsigned int)v4;
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_80EB0, "err ", a1 + 340, "venus_hfi_session_resume", a2);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
