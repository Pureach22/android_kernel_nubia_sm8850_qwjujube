__int64 __fastcall gh_rm_mem_notify(__int64 a1, unsigned int a2, int a3, unsigned __int16 *a4)
{
  int v4; // w22
  char v5; // w23
  int v6; // w24
  unsigned __int16 *v7; // x25
  __int64 v8; // x21
  unsigned __int64 v9; // x19
  __int64 result; // x0
  __int64 v11; // x20
  __int64 v12; // x8
  unsigned __int64 v13; // x12
  unsigned int v14; // w19
  unsigned __int64 StatusReg; // x21
  unsigned int v16; // w20
  unsigned __int16 *v17; // x19
  __int64 v18; // x22
  void (__fastcall *v19)(__int64, _QWORD, _QWORD, _QWORD, unsigned __int16 *); // x8
  __int64 v20; // x0
  __int64 v21; // t1
  __int64 v22; // x8
  unsigned int v23; // [xsp+0h] [xbp-20h]
  unsigned int v24; // [xsp+4h] [xbp-1Ch]
  __int64 v25; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26[0] = 0;
  while ( 1 )
  {
    if ( (unsigned __int8)a2 > 7u
      || (a2 & 1) != 0 && (!a4 || !*a4)
      || (unsigned __int8)a2 >= 2u && a4
      || (v4 = a1, v5 = a2, v6 = a3, v7 = a4, (unsigned int)_sw_hweight8((unsigned __int8)a2) != 1) )
    {
      result = 4294967274LL;
      goto LABEL_12;
    }
    if ( (v5 & 1) != 0 )
    {
      v8 = *v7;
      v9 = 4 * v8 + 16;
    }
    else
    {
      v8 = 0;
      v9 = 12;
    }
    a1 = _kmalloc_noprof(v9, 3520);
    v11 = a1;
    if ( !a1 )
      break;
    *(_DWORD *)a1 = v4;
    *(_BYTE *)(a1 + 4) = v5;
    *(_DWORD *)(a1 + 8) = v6;
    if ( (v5 & 1) == 0 )
      goto LABEL_22;
    if ( (v9 & 0x7FFFE) != 0xC )
    {
      *(_WORD *)(a1 + 12) = v8;
      if ( !v8 )
      {
LABEL_22:
        v14 = gunyah_rm_call(rm, 1358954519, a1, v9, v26, &v25);
        if ( v14 )
        {
          printk(&unk_13114, "gh_rm_mem_notify");
          if ( !v25 )
            goto LABEL_24;
        }
        else if ( !v25 )
        {
LABEL_24:
          kfree(v11);
          result = v14;
          goto LABEL_12;
        }
        __break(0x800u);
        kfree(v26[0]);
        goto LABEL_24;
      }
      v12 = 0;
      v13 = v9 - 16;
      while ( v9 >= v12 * 2 + 16 && v13 >= 2 )
      {
        v13 -= 4LL;
        *(_WORD *)(a1 + 16 + v12 * 2) = v7[v12 + 2];
        v12 += 2;
        if ( 2 * v8 == v12 )
          goto LABEL_22;
      }
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v23 = a1;
      v24 = a2;
      v16 = a3;
      v17 = a4;
      ++*(_DWORD *)(StatusReg + 16);
      v18 = qword_145A0;
      if ( qword_145A0 )
      {
        do
        {
          v19 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, unsigned __int16 *))v18;
          v20 = *(_QWORD *)(v18 + 8);
          if ( *(_DWORD *)(*(_QWORD *)v18 - 4LL) != -1379069491 )
            __break(0x8228u);
          v19(v20, v23, v24, v16, v17);
          v21 = *(_QWORD *)(v18 + 24);
          v18 += 24;
        }
        while ( v21 );
      }
      v22 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v22;
      LODWORD(a1) = v23;
      LOBYTE(a2) = v24;
      if ( !v22 || (a4 = v17, a3 = v16, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(v23, v24);
        LODWORD(a1) = v23;
        LOBYTE(a2) = v24;
        a3 = v16;
        a4 = v17;
      }
    }
  }
  result = 4294967284LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
