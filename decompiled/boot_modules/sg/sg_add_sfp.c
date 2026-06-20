__int64 __fastcall sg_add_sfp(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x9
  __int64 v5; // x2
  __int64 *v6; // x1
  int v7; // w8
  unsigned int v8; // w9
  int v9; // w9
  signed int v10; // w21
  __int64 v11; // x0
  unsigned __int64 v12; // x23
  __int64 v14; // x1
  unsigned int v21; // w8

  v2 = _kmalloc_cache_noprof(cdev_del, 10528, 4952);
  v3 = v2;
  if ( !v2 )
    return -12;
  _init_waitqueue_head(v2 + 24, "&sfp->read_wait", &sg_add_sfp___key);
  *(_QWORD *)(v3 + 48) = 0;
  *(_QWORD *)(v3 + 144) = v3 + 144;
  *(_QWORD *)(v3 + 152) = v3 + 144;
  *(_DWORD *)(v3 + 4912) = 1;
  _mutex_init(v3 + 56, "&sfp->f_mutex", &sg_add_sfp___key_28);
  *(_WORD *)(v3 + 4904) = 0;
  *(_BYTE *)(v3 + 4907) = 0;
  *(_QWORD *)(v3 + 104) = 0x177000003A98LL;
  *(_QWORD *)(v3 + 16) = a1;
  v4 = raw_write_lock_irqsave(a1 + 104);
  if ( !*(_DWORD *)(a1 + 112) )
  {
    v5 = a1 + 88;
    v6 = *(__int64 **)(a1 + 96);
    if ( v3 == a1 + 88 || v6 == (__int64 *)v3 || *v6 != v5 )
    {
      _list_add_valid_or_report(v3);
    }
    else
    {
      *(_QWORD *)(a1 + 96) = v3;
      *(_QWORD *)v3 = v5;
      *(_QWORD *)(v3 + 8) = v6;
      *v6 = v3;
    }
    raw_write_unlock_irqrestore(a1 + 104, v4);
    v7 = sg_big_buff;
    if ( sg_big_buff != def_reserved_size )
    {
      v7 = def_reserved_size;
      sg_big_buff = def_reserved_size;
    }
    v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 8LL) + 156LL);
    if ( v8 >= 0x3FFFFF )
      v8 = 0x3FFFFF;
    v9 = v8 << 9;
    if ( v7 >= v9 )
      v7 = v9;
    do
    {
      if ( (unsigned int)v7 <= 0x1000 )
        v10 = 4096;
      else
        v10 = v7;
      if ( !(unsigned int)sg_build_indirect(v3 + 112, v3, v10) )
        break;
      v11 = *(_QWORD *)(v3 + 128);
      if ( v11 && *(_DWORD *)(v3 + 116) && !*(_BYTE *)(v3 + 140) )
      {
        if ( *(_WORD *)(v3 + 112) )
        {
          v12 = 0;
          while ( 1 )
          {
            v11 = *(_QWORD *)(v3 + 128);
            if ( !*(_QWORD *)(v11 + 8 * v12) )
              break;
            _free_pages(*(_QWORD *)(v11 + 8 * v12++), *(unsigned int *)(v3 + 136));
            if ( v12 >= *(unsigned __int16 *)(v3 + 112) )
            {
              v11 = *(_QWORD *)(v3 + 128);
              break;
            }
          }
        }
        kfree(v11);
      }
      v7 = v10 >> 1;
      *(_QWORD *)(v3 + 128) = 0;
      *(_QWORD *)(v3 + 136) = 0;
      *(_QWORD *)(v3 + 112) = 0;
      *(_QWORD *)(v3 + 120) = 0;
    }
    while ( (unsigned int)(v10 >> 1) > 0x800 );
    _X0 = (unsigned int *)(a1 + 168);
    __asm { PRFM            #0x11, [X0] }
    do
      v21 = __ldxr(_X0);
    while ( __stxr(v21 + 1, _X0) );
    if ( v21 )
    {
      if ( (((v21 + 1) | v21) & 0x80000000) == 0 )
      {
LABEL_30:
        _module_get(&_this_module);
        return v3;
      }
      v14 = 1;
    }
    else
    {
      v14 = 2;
    }
    refcount_warn_saturate(_X0, v14);
    goto LABEL_30;
  }
  raw_write_unlock_irqrestore(a1 + 104, v4);
  kfree(v3);
  return -19;
}
