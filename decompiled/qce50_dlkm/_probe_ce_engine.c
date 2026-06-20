__int64 __fastcall probe_ce_engine(__int64 *a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w21
  int v4; // w22
  int v5; // w23
  __int64 result; // x0
  unsigned int v7; // w20
  __int64 v8; // x8
  int v9; // w0
  __int64 v10; // x8
  int v11; // w5

  v2 = readl_relaxed((unsigned int *)(a1[10] + 106496));
  v3 = HIBYTE(v2);
  __dsb(0xFu);
  v4 = BYTE2(v2);
  v5 = (unsigned __int16)v2;
  if ( HIBYTE(v2) <= 4u )
  {
    printk(&unk_14B71, "_probe_ce_engine", *((unsigned int *)a1 + 22));
    return 4294967291LL;
  }
  v7 = v2;
  if ( v2 <= 0x5FFFFFF )
  {
    *((_DWORD *)a1 + 17564) = -1;
    *((_BYTE *)a1 + 128) = BYTE2(v2) > 2u;
    if ( BYTE2(v2) < 4u && (BYTE2(v2) != 3 || !(_WORD)v2) )
    {
      *((_BYTE *)a1 + 129) = 0;
      goto LABEL_9;
    }
  }
  else
  {
    *((_DWORD *)a1 + 17564) = 0x3FFFF;
    *((_BYTE *)a1 + 128) = 1;
  }
  *((_BYTE *)a1 + 129) = 1;
LABEL_9:
  v8 = a1[10];
  *((_DWORD *)a1 + 101) = BYTE2(v2);
  *((_DWORD *)a1 + 102) = v3;
  *((_DWORD *)a1 + 103) = (unsigned __int16)v2;
  v9 = readl_relaxed((unsigned int *)(v8 + 106760));
  v10 = *a1;
  v11 = *((_DWORD *)a1 + 22);
  *((_DWORD *)a1 + 36) = v9;
  dev_info(v10, "QTI Crypto %d.%d.%d device found @0x%x\n", v3, v4, v5, v11);
  result = 0;
  *((_DWORD *)a1 + 100) = 64;
  *((_BYTE *)a1 + 70260) = v7 > 0x508FFFF;
  return result;
}
