__int64 __fastcall msr_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  unsigned __int64 v4; // x23
  unsigned __int64 v5; // x8
  __int64 v7; // x8
  int v8; // w21
  int v9; // w0

  v3 = -22;
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( v4 )
  {
    if ( v4 <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(v4 + 162) == 1 )
    {
      v5 = *(_QWORD *)(v4 + 48);
      if ( v5 )
      {
        if ( v5 <= 0xFFFFFFFFFFFFF000LL )
        {
          if ( (unsigned __int64)(*(_QWORD *)(v4 + 24) - *(_QWORD *)(v4 + 16) + 1LL) >= 4 )
          {
            v7 = 0;
            v3 = 0;
            v8 = 0;
            do
            {
              v9 = scnprintf(a3 + v3, 4096 - v3, "%d 0x%x\n", v8++, *(_DWORD *)(*(_QWORD *)(v4 + 48) + 4 * v7));
              v7 = v8;
              v3 += v9;
            }
            while ( v8 < (unsigned __int64)(*(_QWORD *)(v4 + 24) - *(_QWORD *)(v4 + 16) + 1LL) >> 2 );
          }
          else
          {
            return 0;
          }
        }
      }
    }
  }
  return v3;
}
