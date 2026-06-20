__int64 __fastcall setup_gx_arc_votes_1(__int64 a1, __int64 a2, int *a3, __int64 a4, __int64 a5)
{
  __int64 v10; // x0
  unsigned __int64 v11; // x4
  __int64 v12; // x20
  unsigned __int64 v13; // x8
  unsigned int v14; // w10
  __int64 v15; // x14
  __int64 v16; // t2
  __int64 result; // x0
  __int64 v18; // x8
  int v19; // w15
  __int64 v20; // x13
  unsigned int v21; // w1
  int v22; // w14
  int v23; // w15
  int v24; // w16
  bool v26; // w17
  __int16 v27; // w1
  __int16 v29; // w14
  __int64 v30; // x10
  unsigned int v31; // kr00_4
  unsigned int v32; // w17
  _DWORD *v33; // x17
  int v34; // w0
  _QWORD v35[16]; // [xsp+8h] [xbp-1C8h] BYREF
  _QWORD v36[16]; // [xsp+88h] [xbp-148h] BYREF
  _QWORD v37[16]; // [xsp+108h] [xbp-C8h] BYREF
  _QWORD v38[9]; // [xsp+188h] [xbp-48h] BYREF

  v38[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = to_gen8_gmu(a1);
  v11 = (unsigned int)(*(_DWORD *)(a1 + 10068) + 1);
  memset(v36, 0, sizeof(v36));
  memset(v35, 0, sizeof(v35));
  *(_DWORD *)(v10 + 1288) = v11;
  if ( (unsigned int)v11 >= 0x21 )
  {
    dev_err(*(_QWORD *)a1, "Defined more GPU DCVS levels than RPMh can support\n");
    result = 4294967262LL;
    goto LABEL_45;
  }
  v12 = v10;
  memset(v38, 0, 64);
  memset(v37, 0, sizeof(v37));
  if ( (unsigned int)v11 >= 2 )
  {
    v13 = 1;
    v14 = *(_DWORD *)(a1 + 10068) - 1;
    do
    {
      if ( (v14 | (unsigned int)v13) >= 0x20 )
        goto LABEL_47;
      if ( v13 > 0x1F )
      {
LABEL_46:
        __break(1u);
        goto LABEL_47;
      }
      v15 = a1 + 9144 + 28LL * v14--;
      v16 = v15 + 20;
      LODWORD(v15) = *(_DWORD *)(v15 + 20);
      *((_WORD *)v38 + v13) = *(_DWORD *)(v16 + 4);
      *((_DWORD *)v37 + v13++) = v15;
    }
    while ( v13 < v11 );
  }
  if ( a4 )
  {
    result = adreno_rpmh_setup_volt_dependency_tbl(v36, a2, a4, v38, v11);
    if ( (_DWORD)result )
      goto LABEL_45;
  }
  else
  {
    result = adreno_rpmh_setup_volt_dependency_tbl(v36, a2, a3, v38, v11);
    if ( (_DWORD)result )
      goto LABEL_45;
  }
  v18 = *(unsigned int *)(v12 + 1288);
  if ( (unsigned int)v18 >= 2 )
  {
    v19 = 1;
    while ( 1 )
    {
      if ( (unsigned __int64)(4LL * v19) > 0x80 || v19 == 32 )
        goto LABEL_46;
      v20 = v19;
      v21 = *((_DWORD *)v37 + v19);
      if ( v21 == -1 )
      {
        LOBYTE(v22) = -1;
      }
      else
      {
        if ( !*(_DWORD *)a5 )
        {
LABEL_43:
          printk(&unk_1419BE);
          result = 4294967274LL;
          goto LABEL_45;
        }
        v22 = 0;
        while ( v21 > *(unsigned __int16 *)(*(_QWORD *)(a5 + 8) + 2LL * v22) )
        {
          if ( *(_DWORD *)a5 == ++v22 )
            goto LABEL_43;
        }
      }
      v23 = *a3;
      v24 = 0;
      v26 = (unsigned __int64)(2 * v20) > 0x40 || (_DWORD)v20 == 32;
      while ( v23 != v24 )
      {
        if ( v26 )
          goto LABEL_46;
        v27 = v24 + 1;
        if ( *a3 - 1 != v24
          && *(unsigned __int16 *)(*((_QWORD *)a3 + 1) + 2LL * v24++) < (unsigned int)*((unsigned __int16 *)v38 + v20) )
        {
          continue;
        }
        LOWORD(v23) = v27 - 1;
        break;
      }
      if ( (unsigned __int64)(4 * v20) > 0x80 || (_DWORD)v20 == 32 )
        goto LABEL_46;
      v29 = (unsigned __int8)v22 | (unsigned __int16)((_WORD)v23 << 8);
      v19 = v20 + 1;
      *((_DWORD *)v35 + v20) = *(_DWORD *)&v29 | 0xFFFFC000;
      if ( (_DWORD)v20 + 1 == (_DWORD)v18 )
      {
        v30 = 1;
        while ( 1 )
        {
          v32 = *(_DWORD *)(a1 + 10068) - v30;
          if ( (v32 | (unsigned int)v30) > 0x1F )
            break;
          v31 = *(_DWORD *)(a1 + 9144 + 28LL * v32);
          v33 = (_DWORD *)(v12 + 1296 + 12 * v30);
          v33[2] = v31 / 0x3E8;
          if ( (v30 & 0x3FFFFFFFFFFFFFE0LL) != 0 )
            goto LABEL_46;
          *v33 = *((_DWORD *)v36 + v30);
          if ( (unsigned __int64)(4 * v30) > 0x80 )
            goto LABEL_46;
          v34 = *((_DWORD *)v35 + v30++);
          v33[1] = v34;
          if ( v30 == v18 )
            goto LABEL_42;
        }
LABEL_47:
        __break(0x5512u);
      }
    }
  }
LABEL_42:
  result = 0;
  *(_DWORD *)(v12 + 1304) = 0;
  *(_QWORD *)(v12 + 1296) = 0xFFFFFFFF00000000LL;
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
