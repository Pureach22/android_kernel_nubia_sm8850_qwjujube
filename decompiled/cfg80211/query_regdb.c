__int64 __fastcall query_regdb(unsigned __int8 *a1)
{
  __int64 v2; // x20
  __int64 v3; // x19
  unsigned int v4; // w8
  unsigned __int8 *v5; // x20
  unsigned __int8 *v6; // x23
  unsigned __int64 v7; // x22
  __int64 v8; // x21
  int v9; // w8
  unsigned __int64 v10; // x24
  unsigned __int64 v11; // x25
  unsigned __int64 v12; // x26
  unsigned __int64 v13; // x8
  unsigned __int8 *v14; // x2
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x9
  int v17; // w11
  unsigned __int8 v18; // w12
  __int64 v20; // x19
  __int64 *v21; // x1
  unsigned __int64 StatusReg; // x24
  __int64 v23; // x25

  v2 = regdb;
  if ( !(unsigned int)rtnl_is_locked(a1) && (query_regdb___already_done & 1) == 0 )
  {
    query_regdb___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 989);
    __break(0x800u);
  }
  v3 = regdb;
  if ( (unsigned __int64)regdb < 0xFFFFFFFFFFFFF001LL )
  {
    v4 = *(unsigned __int16 *)(v2 + 10);
    if ( *(_WORD *)(v2 + 10) )
    {
      v5 = (unsigned __int8 *)(v2 + 8);
      while ( !a1 || !v5 || *a1 != *v5 || a1[1] != v5[1] )
      {
        v4 = *((unsigned __int16 *)v5 + 3);
        v5 += 4;
        if ( !v4 )
          goto LABEL_58;
      }
      v6 = (unsigned __int8 *)(regdb + 4LL * (bswap32(v4) >> 16));
      v7 = 96LL * v6[1] + 32;
      v8 = _kmalloc_noprof(v7, 3520);
      if ( v8 )
      {
        while ( 1 )
        {
          v9 = v6[1];
          *(_DWORD *)(v8 + 16) = v9;
          *(_BYTE *)(v8 + 20) = *v5;
          *(_BYTE *)(v8 + 21) = v5[1];
          *(_DWORD *)(v8 + 24) = v6[2];
          if ( !v9 )
            break;
          v10 = 0;
          v11 = v7 - 116;
          v12 = 116;
          while ( 1 )
          {
            v13 = v12 - 88;
            if ( v7 < v12 - 88 )
              break;
            if ( v11 + 88 < 4 )
              break;
            if ( v7 < v13 )
              break;
            if ( v11 + 88 < 4 )
              break;
            v14 = (unsigned __int8 *)(v3 + 4LL
                                         * (bswap32(*(unsigned __int16 *)&v6[2 * v10 + ((*v6 + 1) & 0x1FE)]) >> 16));
            *(_DWORD *)(v13 + v8) = bswap32(*((_DWORD *)v14 + 1));
            if ( v7 < v12 - 84 )
              break;
            if ( v11 + 84 < 4 )
              break;
            if ( v7 < v12 - 84 )
              break;
            if ( v11 + 84 < 4 )
              break;
            *(_DWORD *)(v8 + v12 - 84) = bswap32(*((_DWORD *)v14 + 2));
            if ( v7 < v12 - 80 )
              break;
            if ( v11 + 80 < 4 )
              break;
            if ( v7 < v12 - 80 )
              break;
            if ( v11 + 80 < 4 )
              break;
            *(_DWORD *)(v8 + v12 - 80) = bswap32(*((_DWORD *)v14 + 3));
            if ( v7 < v12 - 76 )
              break;
            if ( v11 + 76 < 4 )
              break;
            if ( v7 < v12 - 76 )
              break;
            if ( v11 + 76 < 4 )
              break;
            *(_DWORD *)(v8 + v12 - 76) = 0;
            if ( v7 < v12 - 72 )
              break;
            if ( v11 + 72 < 4 )
              break;
            if ( v7 < v12 - 72 )
              break;
            if ( v11 + 72 < 4 )
              break;
            v15 = v12 - 4;
            v16 = v8 + v12;
            *(_DWORD *)(v8 + v12 - 72) = bswap32(*((unsigned __int16 *)v14 + 1)) >> 16;
            if ( v7 < v12 - 4 || v11 >= 0xFFFFFFFFFFFFFFFCLL || v7 < v15 )
              break;
            *(_DWORD *)(v16 - 4) = 0;
            v17 = v14[1] & 1;
            *(_DWORD *)(v16 - 4) = v17;
            v18 = v14[1];
            if ( (v18 & 2) != 0 )
            {
              if ( v7 < v15 )
                break;
              v17 |= 8u;
              *(_DWORD *)(v16 - 4) = v17;
              v18 = v14[1];
            }
            if ( (v18 & 4) != 0 )
            {
              if ( v7 < v15 )
                break;
              v17 |= 0x10u;
              *(_DWORD *)(v16 - 4) = v17;
              v18 = v14[1];
            }
            if ( (v18 & 8) != 0 )
            {
              if ( v7 < v15 )
                break;
              v17 |= 0x80u;
              *(_DWORD *)(v16 - 4) = v17;
              v18 = v14[1];
            }
            if ( (v18 & 0x10) != 0 )
            {
              if ( v7 < v15 )
                break;
              *(_DWORD *)(v16 - 4) = v17 | 0x800;
            }
            if ( v7 < v12 || v11 < 4 || v7 < v12 )
              break;
            *(_DWORD *)(v8 + v12) = 0;
            if ( *v14 >= 0x12u )
            {
              if ( v7 < v12 )
                break;
              *(_DWORD *)(v8 + v12) = 1000 * (bswap32(*((unsigned __int16 *)v14 + 8)) >> 16);
              if ( *v14 >= 0x14u )
                set_wmm_rule(v3, (__int64)v5, (__int64)v14, v13 + v8);
            }
            ++v10;
            v11 -= 96LL;
            v12 += 96LL;
            if ( v10 >= *(unsigned int *)(v8 + 16) )
              goto LABEL_60;
          }
          __break(1u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v23 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &regdb_query_country__alloc_tag;
          v7 = 96LL * v6[1] + 32;
          v8 = _kmalloc_noprof(v7, 3520);
          *(_QWORD *)(StatusReg + 80) = v23;
          if ( !v8 )
            goto LABEL_66;
        }
LABEL_60:
        v20 = _kmalloc_cache_noprof(mod_timer, 3520, 24);
        if ( v20 )
        {
          *(_QWORD *)(v20 + 16) = v8;
          mutex_lock(&reg_regdb_apply_mutex);
          v21 = (__int64 *)off_4F30;
          if ( off_4F30 == (_UNKNOWN **)v20 || *off_4F30 != (_UNKNOWN *)&reg_regdb_apply_list )
          {
            _list_add_valid_or_report(v20, off_4F30);
          }
          else
          {
            off_4F30 = (_UNKNOWN **)v20;
            *(_QWORD *)v20 = &reg_regdb_apply_list;
            *(_QWORD *)(v20 + 8) = v21;
            *v21 = v20;
          }
          mutex_unlock(&reg_regdb_apply_mutex);
          queue_work_on(32, system_wq, &reg_regdb_work);
          LODWORD(v3) = 0;
        }
        else
        {
          kfree(v8);
          LODWORD(v3) = -12;
        }
      }
      else
      {
LABEL_66:
        LODWORD(v3) = -12;
      }
    }
    else
    {
LABEL_58:
      LODWORD(v3) = -61;
    }
  }
  return (unsigned int)v3;
}
