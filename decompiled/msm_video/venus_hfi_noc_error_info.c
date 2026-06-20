__int64 __fastcall venus_hfi_noc_error_info(__int64 a1)
{
  unsigned int v2; // w20
  unsigned int v3; // w0
  __int64 v4; // x8
  void (__fastcall *v5)(_QWORD); // x8

  if ( *(_QWORD *)(a1 + 4560) )
  {
    core_lock(a1);
    v2 = 0;
    if ( !is_core_state(a1, 0) )
    {
      v3 = _resume(a1);
      if ( v3 )
      {
        v2 = v3;
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_819EC, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_noc_error_info");
      }
      else
      {
        if ( a1 )
        {
          v4 = *(_QWORD *)(a1 + 6544);
          if ( v4 )
          {
            v5 = *(void (__fastcall **)(_QWORD))(v4 + 56);
            if ( v5 )
            {
              if ( *((_DWORD *)v5 - 1) != -1850880742 )
                __break(0x8228u);
              v5(a1);
            }
          }
        }
        v2 = 0;
      }
    }
    core_unlock(a1);
  }
  else
  {
    return 0;
  }
  return v2;
}
