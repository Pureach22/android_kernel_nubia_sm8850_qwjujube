__int64 __fastcall ipa3_read_rt(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x1
  __int64 v4; // x1
  _QWORD *v5; // x21
  void *v6; // x0
  __int64 v7; // x1
  void *v8; // x0
  __int64 v9; // x1
  _QWORD *i; // x20
  __int64 *v12; // x24
  unsigned int v13; // w27
  __int64 v14; // x8
  unsigned int v15; // w28
  __int64 v16; // x1
  void *v17; // x0
  unsigned int v18; // w26

  v1 = *(_QWORD *)(a1 + 32);
  if ( (unsigned int)v1 >= 3uLL
    || (v2 = ipa3_ctx, mutex_lock(ipa3_ctx + 29472), printk(&unk_3EC022, v3), (unsigned int)v1 == 2) )
  {
    __break(0x5512u);
    return ipa3_open_dbg();
  }
  else
  {
    v5 = (_QWORD *)(v2 + 48LL * (unsigned int)v1 + 29184);
    if ( *(_BYTE *)(ipa3_ctx + (unsigned int)v1 + 30464) )
      v6 = &unk_3AF3CB;
    else
      v6 = &unk_3CC074;
    printk(v6, v4);
    if ( *(_BYTE *)(ipa3_ctx + (unsigned int)v1 + 30466) )
      v8 = &unk_3E5FF3;
    else
      v8 = &unk_3B7B12;
    printk(v8, v7);
    for ( i = (_QWORD *)*v5; i != v5; i = (_QWORD *)*i )
    {
      v12 = (__int64 *)i[3];
      if ( v12 != i + 3 )
      {
        v13 = 0;
        do
        {
          printk(&unk_3D5446, *(unsigned int *)(v12[25] + 72));
          if ( v12[27] && (ipa3_check_idr_if_freed() & 1) == 0 )
          {
            v18 = (unsigned int)(*(_DWORD *)(ipa3_ctx + 29176) + *(_DWORD *)(*(_QWORD *)(v12[27] + 56) + 16LL)) >> 5;
            ipa_get_ep_mapping(*((unsigned int *)v12 + 5));
            printk(&unk_3AF3F5, v13);
            v17 = &unk_3E6021;
            v16 = v18;
          }
          else
          {
            v14 = v12[26];
            if ( v14 )
              v15 = *(_DWORD *)(*(_QWORD *)(v14 + 328) + 16LL);
            else
              v15 = 0;
            ipa_get_ep_mapping(*((unsigned int *)v12 + 5));
            printk(&unk_3AF3F5, v13);
            v16 = v15 >> 2;
            v17 = &unk_3AC507;
          }
          printk(v17, v16);
          printk(&unk_3E36DF, *((unsigned __int16 *)v12 + 117));
          printk(&unk_3E9273, *((unsigned __int8 *)v12 + 188));
          printk(&unk_3A659F, *((unsigned __int8 *)v12 + 185));
          if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x15u )
          {
            printk(&unk_3FAD68, *((unsigned __int8 *)v12 + 190));
            if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x18u )
              printk(&unk_3CF67D, *((unsigned __int8 *)v12 + 191));
          }
          ipa3_attrib_dump(v12 + 4, (unsigned int)v1);
          v12 = (__int64 *)*v12;
          ++v13;
        }
        while ( v12 != i + 3 );
      }
    }
    printk(&unk_3C08FF, v9);
    mutex_unlock(ipa3_ctx + 29472);
    return 0;
  }
}
