__int64 __fastcall ufs_qcom_set_caps(__int64 result)
{
  __int64 v1; // x8
  int v2; // w9
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 184);
    if ( (*(_BYTE *)(v1 + 360) & 1) == 0 )
    {
      v2 = *(_DWORD *)(result + 3000);
      *(_DWORD *)(result + 3000) = v2 | 0x120F;
      if ( (*(_BYTE *)(v1 + 761) & 1) == 0 )
        *(_DWORD *)(result + 3000) = v2 | 0x128F;
    }
    if ( *(unsigned __int8 *)(v1 + 174) >= 5u )
      *(_DWORD *)v1 |= 0x10u;
    v3 = *(_QWORD *)(*(_QWORD *)(result + 64) + 592LL);
    if ( v3 )
    {
      if ( v3 <= 0xFFFFFFFFFFFFF000LL )
      {
        v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 184) + 8LL) + 96LL);
        if ( v4 )
        {
          if ( v4 <= 0xFFFFFFFFFFFFF000LL )
          {
            v5 = *(_QWORD *)(v4 + 592);
            if ( v5 )
            {
              if ( v5 <= 0xFFFFFFFFFFFFF000LL )
                *(_DWORD *)(result + 3000) = *(_DWORD *)(result + 3000) & 0xFFFFFFBC | 0x40;
            }
          }
        }
      }
    }
  }
  else
  {
    __break(0x800u);
    return ufs_qcom_advertise_quirks(0);
  }
  return result;
}
