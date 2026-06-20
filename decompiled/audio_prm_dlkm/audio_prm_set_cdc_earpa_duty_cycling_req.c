__int64 __fastcall audio_prm_set_cdc_earpa_duty_cycling_req(int *a1, int a2)
{
  __int64 v4; // x0
  bool v5; // zf
  __int64 v6; // x20
  int v7; // w8
  int v8; // w9
  int v9; // w10
  int v10; // w8
  unsigned int v11; // w19

  v4 = _kmalloc_cache_noprof(prepare_to_wait_event, 3520, 124);
  if ( v4 )
  {
    v5 = a2 == 0;
    *(_DWORD *)v4 = 31840;
    *(_WORD *)(v4 + 4) = 770;
    v6 = v4;
    *(_QWORD *)(v4 + 8) = 0x200000007LL;
    if ( v5 )
      v7 = 16781328;
    else
      v7 = 16781327;
    *(_DWORD *)(v4 + 16) = 0;
    *(_DWORD *)(v4 + 20) = v7;
    *(_QWORD *)(v4 + 24) = 0;
    *(_QWORD *)(v4 + 32) = 0x5400000000LL;
    *(_QWORD *)(v4 + 40) = 0x800131B00000002LL;
    *(_QWORD *)(v4 + 48) = 68;
    v8 = *a1;
    v9 = a1[1];
    *(_QWORD *)(v4 + 56) = 0x100000002LL;
    *(_DWORD *)(v4 + 64) = 0;
    *(_DWORD *)(v4 + 68) = v8;
    *(_DWORD *)(v4 + 96) = 0;
    *(_DWORD *)(v4 + 100) = v9;
    *(_QWORD *)(v4 + 72) = 0x100000002LL;
    *(_QWORD *)(v4 + 80) = 0x200000034LL;
    *(_QWORD *)(v4 + 88) = 0x200000024LL;
    *(_QWORD *)(v4 + 104) = 0x300000002LL;
    v10 = a1[3];
    *(_DWORD *)(v4 + 112) = a1[2];
    *(_DWORD *)(v4 + 116) = 4;
    *(_DWORD *)(v4 + 120) = v10;
    v11 = prm_gpr_send_pkt(v4);
    kfree(v6);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v11;
}
