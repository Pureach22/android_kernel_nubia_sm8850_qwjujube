__int64 __fastcall audio_prm_set_lpass_cpu_lpr_req(char a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  int v4; // w8
  unsigned int v5; // w19

  v2 = _kmalloc_cache_noprof(init_wait_entry, 3520, 60);
  if ( v2 )
  {
    *(_DWORD *)v2 = 15456;
    v3 = v2;
    *(_QWORD *)(v2 + 8) = 0x200000007LL;
    *(_WORD *)(v2 + 4) = 770;
    if ( a1 )
      v4 = 16781327;
    else
      v4 = 16781328;
    *(_DWORD *)(v2 + 16) = 0;
    *(_DWORD *)(v2 + 20) = v4;
    *(_QWORD *)(v2 + 24) = 0;
    *(_QWORD *)(v2 + 32) = 0x1400000000LL;
    *(_QWORD *)(v2 + 40) = 0x8001A6E00000002LL;
    *(_QWORD *)(v2 + 48) = 4;
    *(_DWORD *)(v2 + 56) = 1;
    v5 = prm_gpr_send_pkt(v2);
    kfree(v3);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v5;
}
