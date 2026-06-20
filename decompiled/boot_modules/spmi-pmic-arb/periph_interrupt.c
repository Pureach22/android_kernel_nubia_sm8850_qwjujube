__int64 __fastcall periph_interrupt(_QWORD *a1, unsigned int a2)
{
  __int64 v4; // x27
  int v5; // w21
  __int64 (*v6)(void); // x8
  unsigned int *v7; // x0
  __int64 result; // x0
  unsigned int v9; // w22
  __int64 v10; // x0
  unsigned int v11; // w26
  __int64 v13; // x23
  unsigned int v14; // w28
  _DWORD *v15; // x8
  unsigned int *v16; // x0
  unsigned int v17; // [xsp+0h] [xbp-10h]
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v4 = 4LL * (unsigned __int16)a2;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned __int16 *)(a1[19] + v4);
  v6 = *(__int64 (**)(void))(*(_QWORD *)(*a1 + 56LL) + 80LL);
  if ( *((_DWORD *)v6 - 1) != -395291818 )
    __break(0x8228u);
  v7 = (unsigned int *)v6();
  result = readl_relaxed(v7);
  if ( (_DWORD)result )
  {
    v9 = result;
    LODWORD(result) = 0;
    do
    {
      v17 = result;
      while ( 1 )
      {
        v10 = a1[1];
        v18 = 0;
        v11 = __clz(__rbit32(v9));
        v9 &= ~(1 << v11);
        if ( _irq_resolve_mapping(
               v10,
               ((v11 & 7) << 16) | (v5 << 20) & 0xF0000000 | ((unsigned __int8)v5 << 20) | a2 & 0x1FFF,
               &v18)
          && v18 != 0 )
        {
          break;
        }
        v13 = *a1;
        v14 = *(unsigned __int16 *)(a1[19] + v4);
        if ( (unsigned int)__ratelimit(&cleanup_irq__rs, "cleanup_irq") )
          dev_err(
            a1[5],
            "%s apid=%d sid=0x%x per=0x%x irq=%d\n",
            "cleanup_irq",
            (unsigned __int16)a2,
            v14 >> 8,
            (unsigned __int8)v14,
            v11);
        v15 = *(_DWORD **)(*(_QWORD *)(v13 + 56) + 88LL);
        if ( *(v15 - 1) != -395291818 )
          __break(0x8228u);
        v16 = (unsigned int *)((__int64 (__fastcall *)(_QWORD *, _QWORD))v15)(a1, a2);
        writel_relaxed((unsigned __int8)(1 << v11), v16);
        if ( !v9 )
        {
          result = v17;
          goto LABEL_18;
        }
      }
      generic_handle_irq();
      result = v17 + 1;
    }
    while ( v9 );
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
