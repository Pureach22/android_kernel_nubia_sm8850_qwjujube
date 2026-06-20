__int64 __fastcall free_secure_pages(__int64 a1, _QWORD *a2, unsigned int a3)
{
  __int64 result; // x0
  _QWORD *v6; // x21
  __int64 v7; // x0
  unsigned __int64 v8; // x8
  char v9; // w9
  __int64 v10; // x10
  int v11; // w19
  _QWORD v12[3]; // [xsp+8h] [xbp-18h] BYREF

  v12[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 )
  {
    result = 0;
    goto LABEL_13;
  }
  v12[0] = 0;
  v12[1] = 0;
  if ( (unsigned int)sg_alloc_table(v12, a3, 3264) )
  {
    result = 1;
LABEL_13:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v6 = (_QWORD *)*a2;
  if ( (_QWORD *)*a2 == a2 )
  {
LABEL_12:
    v11 = hyp_unassign_sg_from_flags(v12, *(int *)(a1 + 96), 1);
    sg_free_table(v12);
    result = v11 != 0;
    goto LABEL_13;
  }
  v7 = v12[0];
  while ( 1 )
  {
    v8 = (unsigned __int64)(v6 - 1);
    v9 = (*(v6 - 1) & 0x40) != 0 ? *((_BYTE *)v6 + 56) : 0;
    if ( (v8 & 3) != 0 )
      break;
    v10 = *(_QWORD *)v7 & 3LL;
    *(_DWORD *)(v7 + 8) = 0;
    *(_DWORD *)(v7 + 12) = 4096LL << v9;
    *(_QWORD *)v7 = v10 | v8;
    v7 = sg_next(v7);
    v6 = (_QWORD *)*v6;
    if ( v6 == a2 )
      goto LABEL_12;
  }
  __break(0x800u);
  return dma_coerce_mask_and_coherent_0(v7);
}
