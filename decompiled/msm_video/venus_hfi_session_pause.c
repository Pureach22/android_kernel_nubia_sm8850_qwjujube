__int64 __fastcall venus_hfi_session_pause(__int64 a1, unsigned int a2)
{
  __int64 v3; // x19
  int hfi_port; // w0
  __int64 v5; // x21
  unsigned int v6; // w20
  int v7; // w22

  if ( a2 < 2 )
  {
    v3 = a1;
    hfi_port = get_hfi_port(a1, a2);
    v5 = *(_QWORD *)(v3 + 320);
    v6 = *(_DWORD *)(v3 + 332);
    v7 = hfi_port;
    core_lock(v5);
    LODWORD(v3) = venus_hfi_session_command_locked(
                    v3,
                    0x1000011u,
                    3,
                    v7,
                    v6,
                    0,
                    nullptr,
                    0,
                    (__int64)"venus_hfi_session_pause");
    core_unlock(v5);
    return (unsigned int)v3;
  }
  else
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_80EB0, "err ", a1 + 340, "venus_hfi_session_pause", a2);
    }
    return 4294967274LL;
  }
}
