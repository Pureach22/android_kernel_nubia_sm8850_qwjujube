__int64 __fastcall qce_sps_add_cmd(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  _DWORD *v4; // x10
  int v5; // w9
  __int64 v6; // x2

  v4 = (_DWORD *)(*(_QWORD *)(a4 + 8) + 8LL * *(unsigned int *)(a4 + 16));
  v5 = *(unsigned __int16 *)(a3 + 216)
     | ((((*(_QWORD *)a3 - *(_QWORD *)(a1 + 16) + *(_QWORD *)(a1 + 24)) >> 32) & 0xF | a2) << 16)
     | 0x8000000;
  *v4 = *(_DWORD *)a3 - *(_DWORD *)(a1 + 16) + *(_DWORD *)(a1 + 24);
  v4[1] = v5;
  v6 = (unsigned int)(*(_DWORD *)(a4 + 16) + 1);
  *(_DWORD *)(a4 + 16) = v6;
  if ( (unsigned int)v6 < 0x200 )
    return 0;
  printk(&unk_15B74, "_qce_sps_add_cmd", v6);
  return 4294967284LL;
}
