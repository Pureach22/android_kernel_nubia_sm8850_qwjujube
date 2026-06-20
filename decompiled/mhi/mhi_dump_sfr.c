__int64 __fastcall mhi_dump_sfr(__int64 a1)
{
  __int64 **v1; // x22
  __int64 v2; // x9
  __int64 *v3; // x26
  __int64 v4; // x19
  __int64 v5; // x3
  unsigned int v6; // w8
  __int64 v7; // x27
  size_t v8; // x24
  char *v9; // x21
  size_t v10; // x23
  __int64 v11; // x25
  __int64 v12; // x28
  __int64 v13; // x19
  __int64 result; // x0
  unsigned __int64 v15; // x8
  unsigned int v16; // w8
  unsigned int v17; // w10
  __int64 *v18; // x11
  unsigned __int64 v19; // x10
  unsigned __int64 v20; // x19
  char *v21; // x20
  __int64 v22; // x20
  __int64 v23; // x20
  __int64 v24; // x19
  unsigned __int64 StatusReg; // x19
  __int64 v26; // x22
  __int64 v27; // x25
  __int64 v28; // x28
  char **v29; // x8
  unsigned __int64 v30; // x9
  unsigned int v31; // w8
  bool v32; // cf
  unsigned int v33; // w27
  unsigned int v34; // w19
  char **v35; // x8
  unsigned __int64 v36; // x9
  size_t v37; // x8
  __int64 v38; // x19
  unsigned __int64 v39; // x22
  size_t v40; // x2
  size_t v41; // x1
  __int64 v42; // x19
  unsigned int v43; // [xsp+0h] [xbp-20h]
  unsigned __int64 v44; // [xsp+8h] [xbp-18h]
  __int64 v45; // [xsp+10h] [xbp-10h]

  v1 = *(__int64 ***)(a1 + 160);
  v2 = *(_QWORD *)(a1 + 16);
  v3 = *v1;
  v4 = **v1;
  v5 = *(unsigned int *)(v4 + 4);
  if ( (unsigned int)(v5 - 777) <= 0xFFFFFCFE )
  {
    v23 = *(_QWORD *)(v2 + 192);
    result = dev_err(v2 + 40, "[E][%s] invalid reported header size %u\n", "mhi_dump_sfr", v5);
    if ( v23 && *(_DWORD *)(v23 + 24) <= 2u )
      return ipc_log_string(
               *(_QWORD *)(v23 + 32),
               "[E][%s] invalid reported header size %u\n",
               "mhi_dump_sfr",
               *(_DWORD *)(v4 + 4));
  }
  else
  {
    if ( (unsigned int)(v5 - 8) > 0x3F )
    {
      v6 = (unsigned int)(v5 - 8) >> 6;
      v45 = *(_QWORD *)(a1 + 16);
      v7 = 0;
      v8 = 0;
      v9 = (char *)(v4 + v5);
      v10 = (unsigned int)(*((_DWORD *)v3 + 6) - v5);
      v11 = v4 + 8;
      if ( v6 <= 1 )
        v12 = 1;
      else
        v12 = v6;
      while ( v7 != 13 )
      {
        v13 = v11 + (v7 << 6);
        result = strcmp((const char *)(v13 + 44), "Q6-SFR.bin");
        if ( !(_DWORD)result )
        {
          v7 = *(_QWORD *)(v13 + 16);
          v20 = (unsigned int)(v7 + 1);
          result = _kmalloc_noprof(v20, 3520);
          v21 = (char *)result;
          if ( !result )
            return result;
          goto LABEL_30;
        }
        v15 = *(_QWORD *)(v13 + 16);
        if ( v15 <= (unsigned int)v10 )
        {
          v9 += v15;
          v10 = (unsigned int)(v10 - v15);
          goto LABEL_7;
        }
        v16 = v15 - v10;
        if ( !v16 )
        {
LABEL_16:
          v10 = 0;
          goto LABEL_7;
        }
        v17 = v8 + 1;
        while ( 1 )
        {
          if ( *((_DWORD *)v1 + 4) == v17 )
          {
            v22 = *(_QWORD *)(v45 + 192);
            result = dev_err(
                       v45 + 40,
                       "[E][%s] invalid size for file %s\n",
                       "mhi_find_next_file_offset",
                       (const char *)(v13 + 44));
            if ( v22 )
            {
              if ( *(_DWORD *)(v22 + 24) <= 2u )
                return ipc_log_string(
                         *(_QWORD *)(v22 + 32),
                         "[E][%s] invalid size for file %s\n",
                         "mhi_find_next_file_offset",
                         (const char *)(v13 + 44));
            }
            return result;
          }
          v8 = v17;
          v18 = &v3[4 * v17];
          v19 = v18[3];
          if ( v19 >= v16 )
            break;
          v16 -= v19;
          v17 = v8 + 1;
          if ( !v16 )
            goto LABEL_16;
        }
        v10 = (unsigned int)v19 - v16;
        v9 = (char *)(*v18 + v16);
LABEL_7:
        if ( ++v7 == v12 )
          return result;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v26 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &mhi_process_sfr__alloc_tag;
      result = _kmalloc_noprof(14, 3520);
      v21 = (char *)result;
      *(_QWORD *)(StatusReg + 80) = v26;
      v20 = 14;
      if ( !result )
        return result;
LABEL_30:
      if ( (_DWORD)v7 )
      {
        if ( !(_DWORD)v10 )
        {
          v29 = (char **)&v3[4 * (unsigned int)v8];
          v30 = (unsigned __int64)v29[3];
          v9 = *v29;
          if ( v30 >= (unsigned int)v7 )
            v10 = (unsigned int)v7;
          else
            v10 = (unsigned int)v30;
        }
        v31 = v7;
        v32 = (unsigned int)v7 >= (unsigned int)v10;
        v33 = v7 - v10;
        if ( v33 != 0 && v32 )
        {
          v10 = (unsigned int)v10;
          v43 = v31;
          v44 = v20;
          if ( v20 < (unsigned int)v10 )
            goto LABEL_70;
          memcpy(v21, v9, (unsigned int)v10);
          v34 = v8 + 1;
          v21 += (unsigned int)v10;
          if ( (_DWORD)v8 + 1 == *(_DWORD *)(*(_QWORD *)(a1 + 160) + 16LL) )
          {
LABEL_51:
            v38 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
            dev_err(v45 + 40, "[E][%s] invalid size for SFR file\n", "mhi_process_sfr");
            if ( v38 && *(_DWORD *)(v38 + 24) <= 2u )
              ipc_log_string(*(_QWORD *)(v38 + 32), "[E][%s] invalid size for SFR file\n", "mhi_process_sfr");
            return kfree(v21);
          }
          v39 = (unsigned int)v10;
          v27 = (unsigned int)v10;
          v28 = (unsigned int)v10;
          while ( v33 )
          {
            v40 = v33;
            v35 = (char **)&v3[4 * v34];
            v36 = (unsigned __int64)v35[3];
            v9 = *v35;
            if ( v36 >= v33 )
              v8 = v33;
            else
              v8 = (unsigned int)v36;
            v32 = v33 >= (unsigned int)v8;
            v33 -= v8;
            if ( v33 == 0 || !v32 )
            {
              LODWORD(v7) = v43;
              v20 = v44;
              goto LABEL_54;
            }
            v37 = v44 - v10;
            if ( v44 < v10 )
              v37 = 0;
            if ( v37 < v8 )
              goto LABEL_67;
            memcpy(v21, v9, v8);
            ++v34;
            v10 += v8;
            v39 += v8;
            v27 += v8;
            v28 += v8;
            v21 += v8;
            if ( v34 == *(_DWORD *)(*(_QWORD *)(a1 + 160) + 16LL) )
              goto LABEL_51;
          }
          LODWORD(v7) = v43;
          v20 = v44;
        }
        else
        {
          v39 = 0;
          v27 = 0;
          v28 = 0;
          v40 = v31;
          LODWORD(v7) = v31;
LABEL_54:
          if ( v20 >= v39 )
            v41 = v20 - v39;
          else
            v41 = 0;
          if ( v41 < v40 )
            goto LABEL_69;
          memcpy(v21, v9, v40);
        }
      }
      else
      {
        v27 = 0;
        v28 = 0;
      }
      v37 = (unsigned int)v7;
      if ( v20 <= v27 + (unsigned __int64)(unsigned int)v7 || v20 <= v28 + (unsigned __int64)(unsigned int)v7 )
      {
        __break(1u);
LABEL_67:
        v44 = v37;
        while ( 1 )
        {
          _fortify_panic(17, v44, v8);
LABEL_69:
          _fortify_panic(17, v41, v40);
LABEL_70:
          v8 = v10;
        }
      }
      v21[(unsigned int)v7] = 0;
      v42 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      dev_err(v45 + 40, "[E][%s] %s\n", "mhi_process_sfr", v21);
      if ( v42 && *(_DWORD *)(v42 + 24) <= 2u )
        ipc_log_string(*(_QWORD *)(v42 + 32), "[E][%s] %s\n", "mhi_process_sfr", v21);
      return kfree(v21);
    }
    v24 = *(_QWORD *)(v2 + 192);
    result = dev_err(v2 + 40, "[E][%s] invalid rddm table size %u\n", "mhi_dump_sfr", 0);
    if ( v24 && *(_DWORD *)(v24 + 24) <= 2u )
      return ipc_log_string(*(_QWORD *)(v24 + 32), "[E][%s] invalid rddm table size %u\n", "mhi_dump_sfr", 0);
  }
  return result;
}
