__int64 __fastcall msm_pcie_config_sid(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x19
  __int64 v3; // x20
  int v4; // w0
  int v5; // w8
  unsigned int v6; // w22
  __int64 v7; // x8
  unsigned int *v8; // x21
  unsigned int v9; // w25
  unsigned int v10; // w23
  __int64 v11; // x8
  unsigned __int16 *v12; // x26
  unsigned __int8 v13; // w22
  __int64 i; // x8
  __int64 v15; // x24
  int v16; // w0
  unsigned __int8 v17; // w27
  unsigned int v18; // w23
  int v19; // w8
  int v20; // w10
  __int64 v21; // x11
  __int16 v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(result + 1656) )
  {
    v1 = *(_QWORD *)(result + 872);
    v2 = result;
    v3 = v1 + 0x2000;
    v4 = readl_relaxed_0((unsigned int *)(v1 + 11264));
    writel_relaxed_0(v4 & 0xFFFFFFFE, (unsigned int *)(v1 + 11264));
    readl_relaxed_0((unsigned int *)(v1 + 11264));
    result = _memset_io(v1 + 0x2000, 0, 1024);
    v5 = *(_DWORD *)(v2 + 1648);
    if ( (*(_BYTE *)(v2 + 1357) & 1) != 0 )
    {
      if ( v5 )
      {
        v6 = 0;
        do
        {
          v7 = *(_QWORD *)(v2 + 1656) + 16LL * (int)v6;
          v8 = (unsigned int *)(v3 + 4LL * *(unsigned __int8 *)(v7 + 3));
          writel_relaxed_0(*(_DWORD *)(v7 + 12), v8);
          result = readl_relaxed_0(v8);
          ++v6;
        }
        while ( v6 < *(_DWORD *)(v2 + 1648) );
      }
    }
    else if ( v5 )
    {
      v9 = 0;
      do
      {
        v11 = *(_QWORD *)(v2 + 1656);
        v22 = 0;
        v12 = (unsigned __int16 *)(v11 + 16LL * (int)v9);
        v22 = bswap32(*v12) >> 16;
        v13 = crc8(&msm_pcie_crc8_table, &v22, 2, 0);
        for ( i = v13; ; i = v13 )
        {
          v15 = 4 * i;
          v16 = readl_relaxed_0((unsigned int *)(v3 + 4 * i));
          if ( !v16 )
            break;
          v17 = v13++;
          if ( !(_BYTE)v16 )
          {
            v18 = v16 | v13;
            writel_relaxed_0(v18, (unsigned int *)(v3 + 4LL * v17));
            readl_relaxed_0((unsigned int *)(v3 + 4LL * v17));
            v19 = *(_DWORD *)(v2 + 1648);
            if ( v19 )
            {
              v20 = 0;
              while ( 1 )
              {
                v21 = *(_QWORD *)(v2 + 1656) + 16LL * v20;
                if ( *(unsigned __int8 *)(v21 + 3) == v17 )
                  break;
                if ( v19 == ++v20 )
                  goto LABEL_12;
              }
              *(_BYTE *)(v21 + 4) = v13;
              *(_DWORD *)(*(_QWORD *)(v2 + 1656) + 16LL * v20 + 12) = v18;
            }
          }
LABEL_12:
          ;
        }
        v10 = (*v12 << 16) | (*((unsigned __int8 *)v12 + 2) << 8);
        writel_relaxed_0(v10, (unsigned int *)(v3 + v15));
        result = readl_relaxed_0((unsigned int *)(v3 + v15));
        *((_BYTE *)v12 + 3) = v13;
        ++v9;
        *((_DWORD *)v12 + 3) = v10;
      }
      while ( v9 < *(_DWORD *)(v2 + 1648) );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
