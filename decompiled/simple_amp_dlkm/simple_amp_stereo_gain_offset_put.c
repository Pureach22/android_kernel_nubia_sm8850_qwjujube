__int64 __fastcall simple_amp_stereo_gain_offset_put(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x3
  __int64 v3; // x8

  v2 = *(_QWORD *)(a2 + 72);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL);
  if ( v2 >= 0x7D )
  {
    dev_err(v3, "%s: Invalid range,  Val: %ld\n", "simple_amp_stereo_gain_offset_put", v2);
    return 4294967274LL;
  }
  else
  {
    *(_DWORD *)(*(_QWORD *)(v3 + 152) + 160LL) = v2 - 84;
    return 0;
  }
}
