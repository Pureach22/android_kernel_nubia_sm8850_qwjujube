__int64 __fastcall msm_vidc_update_bitstream_buffer_size(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19

  if ( *(_DWORD *)(a1 + 308) == 2 )
  {
    v1 = *(_QWORD *)(a1 + 320);
    if ( v1 )
    {
      v1 = *(_QWORD *)(v1 + 6560);
      if ( v1 )
      {
        v1 = *(_QWORD *)(v1 + 48);
        if ( v1 )
        {
          v2 = a1;
          if ( *(_DWORD *)(v1 - 4) != 1958436756 )
            __break(0x8228u);
          LODWORD(v1) = ((__int64 (__fastcall *)(__int64, __int64))v1)(a1, 1);
          a1 = v2;
        }
      }
    }
    *(_DWORD *)(a1 + 412) = v1;
  }
  return 0;
}
