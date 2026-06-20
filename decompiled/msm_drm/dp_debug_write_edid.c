unsigned __int64 __fastcall dp_debug_write_edid(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x20
  __int64 v8; // x22
  __int64 v9; // x21
  size_t v10; // x23
  unsigned __int64 v11; // x0
  size_t v12; // x24
  unsigned __int64 v13; // x25
  size_t v14; // x27
  unsigned __int64 v15; // x28
  unsigned __int64 v16; // x8
  bool v17; // cf
  __int16 v18; // w8
  __int64 v19; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v23; // x26
  int v24; // [xsp+0h] [xbp-10h] BYREF
  __int16 v25; // [xsp+4h] [xbp-Ch] BYREF
  char v26; // [xsp+6h] [xbp-Ah]
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    mutex_lock(v4 + 376);
    if ( *a4 )
    {
      v8 = 0;
      v9 = 0;
    }
    else
    {
      if ( a3 >= 0x400 )
        v10 = 1024;
      else
        v10 = a3;
      v11 = _kmalloc_noprof(v10, 3520);
      v9 = v11;
      if ( v11 >= 0x11 )
      {
        _check_object_size(v11, v10, 0);
        if ( inline_copy_from_user(v9, a2, v10) )
        {
          v8 = 0;
        }
        else
        {
          v12 = v10 >> 1;
          v8 = _kmalloc_noprof(v10 >> 1, 3520);
          if ( v8 )
          {
            while ( a3 >= 2 )
            {
              v13 = 0;
              v14 = 0;
              v15 = v10;
              while ( 1 )
              {
                v16 = v10 - v13;
                v26 = 0;
                if ( v10 < v13 )
                  v16 = 0;
                v25 = 0;
                v24 = 0;
                if ( v16 <= 1 )
                  break;
                if ( v10 < v13 )
                  goto LABEL_28;
                v17 = v15 >= 2;
                v15 -= 2LL;
                if ( !v17 )
                  goto LABEL_28;
                v18 = *(_WORD *)(v9 + v13);
                v26 = 0;
                v25 = v18;
                v19 = kstrtoint(&v25, 16, &v24);
                if ( (_DWORD)v19 )
                {
                  ipc_log_context = get_ipc_log_context(v19);
                  ipc_log_string(
                    ipc_log_context,
                    "[e][%-4d]kstrtoint error\n",
                    *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
                  printk(&unk_259AF0, "dp_debug_write_edid");
                  goto LABEL_25;
                }
                if ( v12 <= v14 )
                {
LABEL_28:
                  __break(1u);
                  break;
                }
                v13 += 2LL;
                *(_BYTE *)(v8 + v14++) = v24;
                if ( 2 * v12 == v13 )
                  goto LABEL_24;
              }
              _fortify_panic(16, 3, 2);
              StatusReg = _ReadStatusReg(SP_EL0);
              v23 = *(_QWORD *)(StatusReg + 80);
              *(_QWORD *)(StatusReg + 80) = &dp_debug_write_edid__alloc_tag_106;
              v8 = _kmalloc_noprof(v10 >> 1, 3520);
              *(_QWORD *)(StatusReg + 80) = v23;
              if ( !v8 )
                goto LABEL_25;
            }
LABEL_24:
            dp_debug_enable_sim_mode(v4, 1);
            dp_mst_clear_edid_cache(*(_QWORD *)(v4 + 368));
            dp_sim_update_port_edid(*(_QWORD *)(v4 + 424), *(unsigned int *)(v4 + 20), v8, (unsigned int)v12);
          }
        }
      }
      else
      {
        v8 = 0;
        a3 = -12;
      }
    }
LABEL_25:
    kfree(v9);
    kfree(v8);
    mutex_unlock(v4 + 376);
  }
  else
  {
    a3 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
