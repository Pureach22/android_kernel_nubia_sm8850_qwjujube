__int64 __fastcall audio_prm_set_lpass_hw_core_req(int a1, char a2)
{
  __int64 v4; // x0
  bool v5; // zf
  __int64 v6; // x20
  int v7; // w8
  unsigned int v8; // w19

  v4 = _kmalloc_cache_noprof(init_wait_entry, 3520, 60);
  if ( v4 )
  {
    v5 = a2 == 0;
    *(_DWORD *)v4 = 15456;
    v6 = v4;
    *(_DWORD *)(v4 + 56) = a1;
    *(_QWORD *)(v4 + 8) = 0x200000007LL;
    *(_WORD *)(v4 + 4) = 770;
    if ( v5 )
      v7 = 16781328;
    else
      v7 = 16781327;
    *(_DWORD *)(v4 + 16) = 0;
    *(_DWORD *)(v4 + 20) = v7;
    *(_QWORD *)(v4 + 24) = 0;
    *(_QWORD *)(v4 + 32) = 0x1400000000LL;
    *(_QWORD *)(v4 + 40) = 0x800103200000002LL;
    *(_QWORD *)(v4 + 48) = 4;
    v8 = prm_gpr_send_pkt();
    kfree(v6);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v8;
}
