__int64 __fastcall gh_rm_vm_auth_image(__int16 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v4; // x20
  _WORD *v7; // x19
  __int64 v8; // x11
  _WORD *v9; // x9
  int v10; // w10
  unsigned __int64 v11; // x11
  __int64 v12; // x13
  _WORD *v13; // x12
  unsigned int v14; // w0
  unsigned int v15; // w20
  unsigned __int64 StatusReg; // x24
  __int64 v17; // x25
  __int64 v19; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v4 = (8 * a2) | 4;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20[0] = 0;
  v7 = (_WORD *)_kmalloc_noprof(v4, 3520);
  if ( v7 )
  {
    while ( 1 )
    {
      *v7 = a1;
      v7[1] = a2;
      if ( a2 < 1 )
        break;
      v8 = 0;
      v9 = v7 + 2;
      v10 = 1;
      while ( (v8 & 0x8000000000000000LL) == 0 )
      {
        v11 = 4 * v8;
        if ( 4 * a2 <= v11 )
          break;
        v12 = a3 + v11 * 2;
        v13 = &v9[v11];
        *(_DWORD *)&v9[v11] = *(_DWORD *)(a3 + v11 * 2);
        if ( v4 < v11 * 2 + 8 )
          break;
        v8 = v10++;
        *((_DWORD *)v13 + 1) = *(_DWORD *)(v12 + 4);
        if ( v8 >= a2 )
          goto LABEL_8;
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v17 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &gh_rm_vm_auth_image__alloc_tag;
      v7 = (_WORD *)_kmalloc_noprof(v4, 3520);
      *(_QWORD *)(StatusReg + 80) = v17;
      if ( !v7 )
        goto LABEL_15;
    }
LABEL_8:
    v14 = gunyah_rm_call(rm, 1442840586, v7, v4, &v19, v20);
    if ( v14 )
    {
      v15 = v14;
      printk(&unk_1387F, "gh_rm_vm_auth_image");
    }
    else if ( v20[0] )
    {
      printk(&unk_12EA4, "gh_rm_vm_auth_image");
      kfree(v19);
      v15 = -22;
    }
    else
    {
      v15 = 0;
    }
    kfree(v7);
  }
  else
  {
LABEL_15:
    v15 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v15;
}
