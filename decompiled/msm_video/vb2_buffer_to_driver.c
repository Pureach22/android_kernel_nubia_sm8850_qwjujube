__int64 __fastcall vb2_buffer_to_driver(__int64 a1, __int64 a2)
{
  int v3; // w9
  int v4; // w8

  if ( a1 && a2 )
  {
    *(_DWORD *)(a2 + 36) = *(_DWORD *)(a1 + 136);
    v3 = *(_DWORD *)(a1 + 144);
    *(_DWORD *)(a2 + 44) = v3;
    *(_DWORD *)(a2 + 48) = *(_DWORD *)(a1 + 120) - v3;
    *(_DWORD *)(a2 + 40) = *(_DWORD *)(a1 + 124);
    *(_QWORD *)(a2 + 72) = *(_QWORD *)(a1 + 24);
    v4 = *(_DWORD *)(a1 + 576);
    *(_DWORD *)(a2 + 80) = 0;
    *(_DWORD *)(a2 + 64) = v4;
    return 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "vb2_buffer_to_driver");
    return 4294967274LL;
  }
}
