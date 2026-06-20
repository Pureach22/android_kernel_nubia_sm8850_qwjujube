__int64 __fastcall msm_ep_unconfig(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x21
  __int64 v4; // x0
  unsigned int v5; // w8
  __int64 v6; // x23
  __int64 v7; // x19
  int v8; // w9
  unsigned int v9; // w10
  char v10; // w8
  char v11; // w24
  int v12; // w0
  int v13; // w0
  __int64 v14; // x8
  _DWORD *v15; // x9
  int v16; // w24
  int v17; // w0
  __int64 v18; // x9
  int v19; // w8
  int v20; // w10
  __int64 v21; // x11
  int v22; // w12
  int v23; // w11

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 368) + 96LL) + 152LL);
  v4 = raw_spin_lock_irqsave(v1 + 312);
  v5 = *(unsigned __int8 *)(a1 + 170);
  if ( v5 >= 0x20 )
    goto LABEL_23;
  v6 = v3 + 1272;
  v7 = v4;
  v8 = *(_DWORD *)(v3 + 1272 + 40LL * *(unsigned __int8 *)(a1 + 170) + 8);
  if ( v8 == 3 )
  {
    v9 = v5 >> 1;
    v10 = v5 + 15;
    v11 = (*(_BYTE *)(a1 + 204) & 1) != 0 ? v9 : v10;
    v12 = readl(*(_QWORD *)(v3 + 8) + 1018368LL);
    writel(v12 & ~(unsigned int)(1LL << v11), *(_QWORD *)(v3 + 8) + 1018368LL);
    writel(0, *(_QWORD *)(v3 + 8) + 1018368LL);
    v13 = readl(*(_QWORD *)(v3 + 8) + 1018372LL);
    v4 = writel(v13 & 0xFFFFEFFF, *(_QWORD *)(v3 + 8) + 1018372LL);
  }
  else if ( *(unsigned __int8 *)(a1 + 169) == *(unsigned __int8 *)(a1 + 168)
         && *(_QWORD *)(a1 + 96) == a1 + 96
         && *(_QWORD *)(a1 + 112) == a1 + 112 )
  {
    if ( v8 == 1 )
    {
      v14 = v6 + 40LL * *(unsigned __int8 *)(a1 + 170);
      v15 = *(_DWORD **)(v3 + 496);
      v16 = *(unsigned __int8 *)(v14 + 24);
      *(_BYTE *)(v14 + 24) = 0;
      v17 = readl(*(_QWORD *)(v3 + 8) + (unsigned int)(*v15 + v15[1] * v16 + 1015808));
      v4 = writel(
             v17 & 0xFFFFFFFE,
             *(_QWORD *)(v3 + 8)
           + (unsigned int)(**(_DWORD **)(v3 + 496) + *(_DWORD *)(*(_QWORD *)(v3 + 496) + 4LL) * v16 + 1015808));
    }
    v18 = 0;
    v19 = 0;
    v20 = 0;
    do
    {
      v21 = v3 + v18;
      v18 += 80;
      v22 = *(_DWORD *)(v21 + 1280);
      v23 = *(_DWORD *)(v21 + 1320);
      if ( v22 == 1 )
        ++v19;
      if ( v23 == 1 )
        ++v20;
    }
    while ( v18 != 1280 );
    if ( !(v20 + v19) )
    {
      v4 = readl(*(_QWORD *)(v3 + 8) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v3 + 496) + 40LL) + 1015808));
      if ( !(_DWORD)v4 )
      {
        writel(v4, *(_QWORD *)(v3 + 8) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v3 + 496) + 120LL) + 1015808));
        writel(0, *(_QWORD *)(v3 + 8) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v3 + 496) + 128LL) + 1015808));
        v4 = msm_dbm_write_ep_reg_field(v3, 5u, 0, 0xFFFFu, 0);
      }
    }
  }
  if ( *(unsigned __int8 *)(a1 + 170) > 0x1FuLL )
  {
LABEL_23:
    __break(0x5512u);
    return msm_ep_clear_ops(v4);
  }
  else
  {
    *(_QWORD *)(v6 + 40LL * *(unsigned __int8 *)(a1 + 170)) = 0;
    raw_spin_unlock_irqrestore(v1 + 312, v7);
    return 0;
  }
}
