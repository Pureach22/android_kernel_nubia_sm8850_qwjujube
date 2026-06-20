__int64 __fastcall gh_rm_get_vm_id_info(__int64 a1)
{
  __int16 v1; // w20
  unsigned __int64 id; // x0
  unsigned __int64 v3; // x28
  unsigned int v4; // w21
  unsigned int v5; // w26
  unsigned __int8 *v6; // x19
  int v7; // w8
  size_t v8; // x24
  char *v9; // x0
  char *v10; // x25
  size_t v11; // x2
  unsigned int v12; // w2
  char *v13; // x21
  int *v14; // x8
  __int64 v15; // x0
  unsigned int updated; // w0
  unsigned int v18; // [xsp+Ch] [xbp-74h] BYREF
  __int64 v19; // [xsp+10h] [xbp-70h] BYREF
  char *v20; // [xsp+18h] [xbp-68h]
  char *v21; // [xsp+20h] [xbp-60h]
  char *s1; // [xsp+28h] [xbp-58h]
  char *v23; // [xsp+30h] [xbp-50h]
  __int64 v24; // [xsp+38h] [xbp-48h]
  __int64 v25; // [xsp+40h] [xbp-40h]
  __int64 v26; // [xsp+48h] [xbp-38h]
  __int64 v27; // [xsp+50h] [xbp-30h]
  __int64 v28; // [xsp+58h] [xbp-28h]
  __int64 v29; // [xsp+60h] [xbp-20h]
  __int64 v30; // [xsp+68h] [xbp-18h]
  __int64 v31; // [xsp+70h] [xbp-10h]
  __int64 v32; // [xsp+78h] [xbp-8h]

  v1 = a1;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  s1 = nullptr;
  v23 = nullptr;
  v20 = nullptr;
  v21 = nullptr;
  v19 = 0;
  v18 = 0;
  id = gh_rm_vm_get_id(a1, &v18);
  v3 = id;
  if ( !id || id > 0xFFFFFFFFFFFFF000LL )
  {
    v4 = id;
    goto LABEL_38;
  }
  if ( !v18 )
    goto LABEL_24;
  v4 = 0;
  v5 = 0;
  v6 = (unsigned __int8 *)id;
  _ReadStatusReg(SP_EL0);
  do
  {
    v7 = *((unsigned __int16 *)v6 + 1);
    if ( (v7 & 3) != 0 )
      v8 = (unsigned int)(v7 + 1);
    else
      v8 = *((unsigned __int16 *)v6 + 1);
    v9 = (char *)_kmalloc_noprof(v8, 3520);
    v10 = v9;
    if ( !v9 )
    {
      v4 = -12;
      goto LABEL_37;
    }
    v11 = *((unsigned __int16 *)v6 + 1);
    if ( v8 < v11 )
      _fortify_panic(17, v8);
    memcpy(v9, v6 + 4, v11);
    v12 = *v6;
    if ( v12 > 1 )
    {
      if ( v12 == 2 )
      {
        s1 = v10;
        goto LABEL_6;
      }
      if ( v12 == 3 )
      {
        v23 = v10;
        goto LABEL_6;
      }
    }
    else
    {
      if ( !*v6 )
      {
        v20 = v10;
        goto LABEL_6;
      }
      if ( v12 == 1 )
      {
        v21 = v10;
        goto LABEL_6;
      }
    }
    printk(&unk_12AB8, "gh_rm_get_vm_id_info");
    kfree(v10);
    v4 = -22;
LABEL_6:
    ++v5;
    v6 += ((*((unsigned __int16 *)v6 + 1) - 1LL) | 3) + 5;
  }
  while ( v5 < v18 );
  if ( v4 )
    goto LABEL_37;
LABEL_24:
  v13 = s1;
  LOWORD(v19) = v1;
  if ( !s1 )
    goto LABEL_40;
  if ( *s1 )
  {
    if ( !strcmp(s1, "qcom,trustedvm") )
    {
      v14 = &dword_14008;
    }
    else
    {
      if ( strcmp(v13, "qcom,cpusysvm") )
      {
        if ( !strcmp(v13, "qcom,oemvm") )
        {
          v14 = &dword_14038;
          goto LABEL_33;
        }
        printk(&unk_137B9, v13);
LABEL_40:
        printk(&unk_12BC7, v13);
        v4 = -22;
        goto LABEL_37;
      }
      v14 = &dword_14020;
    }
  }
  else
  {
    v14 = &vm_name_map;
  }
LABEL_33:
  v15 = (unsigned int)*v14;
  if ( (_DWORD)v15 == 5 )
    goto LABEL_40;
  updated = gh_update_vm_prop_table(v15, &v19);
  if ( updated == -17 )
    v4 = 0;
  else
    v4 = updated;
LABEL_37:
  kfree(v3);
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return v4;
}
