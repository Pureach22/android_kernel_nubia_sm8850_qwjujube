void __fastcall walt_find_busiest_queue(__int64 a1, unsigned int a2, __int64 a3, _DWORD *a4, _QWORD *a5, _DWORD *a6)
{
  unsigned int v6; // w8
  unsigned int v7; // w9
  _BYTE *v8; // x11
  __int64 v9; // x9
  __int64 v10; // x11
  _QWORD *v11; // x21
  unsigned int busiest_cpu; // w0
  int v13; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = __clz(__rbit64(*(unsigned int *)(a3 + 40)));
  if ( *(_DWORD *)(a3 + 40) )
    v7 = v6;
  else
    v7 = 32;
  if ( (walt_disabled & 1) == 0 )
  {
    *a6 = 1;
    *a5 = 0;
    if ( a2 >= 0x20 )
      goto LABEL_14;
    v8 = &walt_rq[*((_QWORD *)&_per_cpu_offset + a2)];
    if ( (v8[541] & 1) != 0 || (((unsigned __int64)walt_enforce_high_irq_cpu_mask >> a2) & 1) != 0 )
      goto LABEL_13;
    if ( (v7 | a2) >= 0x20 )
LABEL_14:
      __break(0x5512u);
    v9 = *((_QWORD *)&_per_cpu_offset + v7);
    v10 = *((_QWORD *)v8 + 1);
    v14[0] = 0;
    v13 = 0;
    if ( v10 == *(_QWORD *)&walt_rq[v9 + 8] )
    {
LABEL_12:
      *a5 = (char *)&runqueues + v9;
      goto LABEL_13;
    }
    v11 = a5;
    v14[0] = (unsigned int)(*(_DWORD *)(a3 + 40) & *a4);
    busiest_cpu = walt_lb_find_busiest_cpu(a2, v14, &v13, 0);
    if ( busiest_cpu != -1 )
    {
      v9 = *((_QWORD *)&_per_cpu_offset + busiest_cpu);
      a5 = v11;
      goto LABEL_12;
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
}
