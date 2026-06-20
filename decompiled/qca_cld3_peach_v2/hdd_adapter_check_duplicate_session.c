__int64 __fastcall hdd_adapter_check_duplicate_session(__int64 a1)
{
  __int64 v1; // x8
  char v2; // w9
  _DWORD *v3; // x15
  __int64 v4; // x16
  unsigned int v5; // w15
  __int64 v6; // x16
  __int64 v7; // x17
  __int64 v8; // x15
  __int64 v9; // x10
  __int64 result; // x0
  _QWORD v11[5]; // [xsp+8h] [xbp-28h] BYREF

  LODWORD(v1) = 0;
  v11[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_BYTE *)(a1 + 52800);
  memset(v11, 0, 32);
  if ( (v2 & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 40) == 1 || !a1 )
    {
      LODWORD(v1) = 0;
    }
    else if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 && (v3 = (_DWORD *)(a1 + 52840), a1 != -52840)
           || (*(_QWORD *)(a1 + 1640) & 2) != 0 && (v3 = (_DWORD *)(a1 + 58928), a1 != -58928)
           || (LODWORD(v1) = 0, (*(_QWORD *)(a1 + 1640) & 4) != 0) && (v3 = (_DWORD *)(a1 + 65016), a1 != -65016) )
    {
      v1 = 0;
      do
      {
        if ( v1 == 4 )
          goto LABEL_22;
        v4 = v1;
        if ( (v1 & 0x1FFFFFFFFFFFFFFFLL) == 4 )
          goto LABEL_23;
        ++v1;
        v11[v4] = v3 + 18;
        v5 = 73 * ((unsigned int)((_DWORD)v3 - *v3 - 52840) >> 3) + 1;
        if ( (unsigned __int8)v5 > 2u )
          break;
        v6 = (unsigned __int8)v5;
        v3 = nullptr;
        v7 = a1 + 52840 + 6088LL * (unsigned int)v6;
        do
        {
          if ( v3 )
            break;
          v8 = *(_QWORD *)(a1 + 1640) >> v6++;
          v3 = (_DWORD *)((v8 << 63 >> 63) & v7);
          v7 += 6088;
        }
        while ( v6 != 3 );
      }
      while ( v3 );
      if ( (v1 & 0xFFFFFFFC) != 0 )
      {
LABEL_22:
        __break(0x5512u);
LABEL_23:
        __break(1u);
      }
    }
  }
  v9 = *(_QWORD *)(a1 + 24);
  v11[(unsigned int)v1] = a1 + 1617;
  result = sme_check_for_duplicate_session(*(_QWORD *)(v9 + 16), v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
