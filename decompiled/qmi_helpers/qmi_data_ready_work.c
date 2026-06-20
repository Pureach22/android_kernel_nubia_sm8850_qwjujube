__int64 __fastcall qmi_data_ready_work(_QWORD *a1)
{
  _QWORD *v1; // x21
  _QWORD *v3; // x20
  __int64 *v4; // x22
  _DWORD *v5; // x8
  __int64 v6; // x26
  __int64 v7; // x2
  __int64 v8; // x25
  __int64 result; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  _DWORD *v12; // x8
  int v13; // w9
  int v14; // w23
  int v15; // w24
  int v16; // w26
  unsigned int v17; // w27
  __int64 v18; // x25
  _DWORD *v19; // x8
  _QWORD *v20; // x2
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x3
  __int64 v24; // x27
  __int64 v25; // x2
  int v26; // w0
  __int64 v27; // x1
  __int64 v28; // x2
  _DWORD *v29; // x9
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 **v32; // x26
  unsigned int v33; // w25
  _DWORD *v34; // x8
  __int64 **v35; // x25
  int v36; // w24
  int v37; // w27
  __int64 *v38; // x23
  _DWORD *v39; // x8
  __int64 **v40; // x8
  __int64 *v41; // x9
  __int64 *v42; // x23
  _DWORD *v43; // x8
  __int64 **v44; // x8
  __int64 *v45; // x9
  int v46; // w23
  unsigned __int64 v47; // x23
  int v48; // w24
  __int64 **v49; // x24
  _DWORD *v50; // x8
  __int64 *v51; // x26
  __int64 **v52; // x8
  __int64 *v53; // x9
  void (__fastcall *v54)(_QWORD); // x8
  __int64 v55; // x8
  int v56; // w9
  int *i; // x22
  int *v58; // x19
  int *j; // x21
  int *v60; // t1
  _QWORD v61[2]; // [xsp+90h] [xbp-70h] BYREF
  unsigned __int64 v62; // [xsp+A0h] [xbp-60h] BYREF
  __int64 v63; // [xsp+A8h] [xbp-58h] BYREF
  __int64 v64; // [xsp+B0h] [xbp-50h]
  __int64 v65; // [xsp+B8h] [xbp-48h]
  __int64 v66; // [xsp+C0h] [xbp-40h]
  __int64 v67; // [xsp+C8h] [xbp-38h]
  __int64 v68; // [xsp+D0h] [xbp-30h]
  __int64 v69; // [xsp+D8h] [xbp-28h]
  __int64 v70; // [xsp+E0h] [xbp-20h]
  __int64 v71; // [xsp+E8h] [xbp-18h]
  __int64 v72; // [xsp+F0h] [xbp-10h]

  v1 = a1 - 8;
  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v61[1]) = 0;
  v61[0] = 0;
  mutex_lock(a1 - 8);
  v3 = a1 - 9;
  if ( *(a1 - 9) )
  {
    v4 = a1 + 9;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      LODWORD(v8) = kernel_recvmsg();
      result = mutex_unlock(v1);
      if ( (_DWORD)v8 == -11 )
        break;
      if ( (_DWORD)v8 == -102 )
      {
        LODWORD(v64) = 0;
        v62 = 0;
        v63 = 0;
        result = sock_create_kern(&init_net, 42, 2, 42, &v62);
        if ( (result & 0x80000000) != 0 )
        {
          v47 = (int)result;
          if ( (unsigned __int64)(int)result > 0xFFFFFFFFFFFFF000LL )
            break;
        }
        else
        {
          result = kernel_getsockname(v62, &v63);
          v47 = v62;
          if ( (result & 0x80000000) != 0 )
          {
            v48 = result;
            result = sock_release(v62);
            v47 = v48;
            if ( (unsigned __int64)v48 > 0xFFFFFFFFFFFFF000LL )
              break;
          }
          else
          {
            *(_QWORD *)(*(_QWORD *)(v62 + 24) + 648LL) = v3;
            *(_QWORD *)(*(_QWORD *)(v47 + 24) + 264LL) = qmi_data_ready;
            *(_QWORD *)(*(_QWORD *)(v47 + 24) + 696LL) = qmi_data_ready;
            if ( v47 > 0xFFFFFFFFFFFFF000LL )
              break;
          }
        }
        mutex_lock(v1);
        sock_release(*v3);
        *v3 = 0;
        mutex_unlock(v1);
        v49 = (__int64 **)*v4;
        if ( (__int64 *)*v4 != v4 )
        {
          do
          {
            v50 = (_DWORD *)a1[14];
            v51 = *v49;
            if ( v50 )
            {
              if ( *(v50 - 1) != 190001868 )
                __break(0x8228u);
              ((void (__fastcall *)(_QWORD *, __int64 **))v50)(a1 - 9, v49 - 4);
            }
            v52 = (__int64 **)v49[1];
            if ( *v52 == (__int64 *)v49 && (v53 = *v49, (__int64 **)(*v49)[1] == v49) )
            {
              v53[1] = (__int64)v52;
              *v52 = v53;
            }
            else
            {
              _list_del_entry_valid_or_report(v49);
            }
            *v49 = (__int64 *)0xDEAD000000000100LL;
            v49[1] = (__int64 *)0xDEAD000000000122LL;
            kfree(v49 - 4);
            v49 = (__int64 **)v51;
          }
          while ( v51 != v4 );
        }
        v54 = (void (__fastcall *)(_QWORD))a1[15];
        if ( v54 )
        {
          if ( *((_DWORD *)v54 - 1) != -1426447574 )
            __break(0x8228u);
          v54(a1 - 9);
        }
        mutex_lock(v1);
        v55 = v63;
        v56 = v64;
        *(a1 - 9) = v47;
        *(a1 - 2) = v55;
        *((_DWORD *)a1 - 2) = v56;
        result = mutex_unlock(v1);
        for ( i = (int *)a1[7]; i != (int *)(a1 + 7); i = *(int **)i )
          result = qmi_send_new_lookup((__int64)(a1 - 9), i - 8);
        v60 = (int *)a1[11];
        v58 = (int *)(a1 + 11);
        for ( j = v60; j != v58; j = *(int **)j )
          result = qmi_send_new_server((__int64)v3, j - 8);
        break;
      }
      v8 = (int)v8;
      if ( (v8 & 0x80000000) != 0 )
        goto LABEL_107;
      if ( *(_QWORD *)((char *)v61 + 4) == (*((unsigned int *)a1 - 3) | 0xFFFFFFFE00000000LL) )
      {
        if ( (unsigned int)v8 >= 0x14 )
        {
          v12 = (_DWORD *)a1[5];
          v13 = *v12;
          if ( (int)*v12 > 4 )
          {
            if ( v13 == 5 )
            {
              v35 = (__int64 **)*v4;
              if ( (__int64 *)*v4 != v4 )
              {
                v37 = v12[3];
                v36 = v12[4];
                do
                {
                  v42 = *v35;
                  if ( (v37 == -1 || *((_DWORD *)v35 - 5) == v37) && (v36 == -1 || *((_DWORD *)v35 - 4) == v36) )
                  {
                    v43 = (_DWORD *)a1[14];
                    if ( v43 )
                    {
                      if ( *(v43 - 1) != 190001868 )
                        __break(0x8228u);
                      ((void (__fastcall *)(_QWORD *, __int64 **))v43)(a1 - 9, v35 - 4);
                    }
                    v44 = (__int64 **)v35[1];
                    if ( *v44 == (__int64 *)v35 && (v45 = *v35, (__int64 **)(*v35)[1] == v35) )
                    {
                      v45[1] = (__int64)v44;
                      *v44 = v45;
                    }
                    else
                    {
                      _list_del_entry_valid_or_report(v35);
                    }
                    *v35 = (__int64 *)0xDEAD000000000100LL;
                    v35[1] = (__int64 *)0xDEAD000000000122LL;
                    kfree(v35 - 4);
                  }
                  v35 = (__int64 **)v42;
                }
                while ( v42 != v4 );
              }
            }
            else if ( v13 == 6 )
            {
              v29 = (_DWORD *)a1[18];
              if ( v29 )
              {
                v30 = (unsigned int)v12[1];
                v31 = (unsigned int)v12[2];
                if ( *(v29 - 1) != -478199965 )
                  __break(0x8229u);
                ((void (__fastcall *)(_QWORD *, __int64, __int64))v29)(a1 - 9, v30, v31);
              }
            }
          }
          else if ( v13 == 3 )
          {
            v32 = (__int64 **)*v4;
            v33 = v12[1];
            if ( (__int64 *)*v4 != v4 )
            {
              do
              {
                v38 = *v32;
                if ( v33 == -1 || *((_DWORD *)v32 - 5) == v33 )
                {
                  v39 = (_DWORD *)a1[14];
                  if ( v39 )
                  {
                    if ( *(v39 - 1) != 190001868 )
                      __break(0x8228u);
                    ((void (__fastcall *)(_QWORD *, __int64 **))v39)(a1 - 9, v32 - 4);
                  }
                  v40 = (__int64 **)v32[1];
                  if ( *v40 == (__int64 *)v32 && (v41 = *v32, (__int64 **)(*v32)[1] == v32) )
                  {
                    v41[1] = (__int64)v40;
                    *v40 = v41;
                  }
                  else
                  {
                    _list_del_entry_valid_or_report(v32);
                  }
                  *v32 = (__int64 *)0xDEAD000000000100LL;
                  v32[1] = (__int64 *)0xDEAD000000000122LL;
                  kfree(v32 - 4);
                }
                v32 = (__int64 **)v38;
              }
              while ( v38 != v4 );
            }
            v34 = (_DWORD *)a1[17];
            if ( v34 )
            {
              if ( *(v34 - 1) != 198913779 )
                __break(0x8228u);
              ((void (__fastcall *)(_QWORD *, _QWORD))v34)(a1 - 9, v33);
            }
          }
          else if ( v13 == 4 )
          {
            v15 = v12[3];
            v14 = v12[4];
            if ( *(_QWORD *)(v12 + 3) )
            {
              if ( a1[13] )
              {
                v16 = v12[1];
                v17 = v12[2];
                v18 = _kmalloc_cache_noprof(_init_swait_queue_head, 3520, 48);
                if ( v18 )
                {
                  *(_DWORD *)v18 = v16;
                  *(_DWORD *)(v18 + 4) = (unsigned __int8)v17;
                  v19 = (_DWORD *)a1[13];
                  *(_DWORD *)(v18 + 8) = v17 >> 8;
                  *(_DWORD *)(v18 + 12) = v15;
                  *(_DWORD *)(v18 + 16) = v14;
                  if ( *(v19 - 1) != 1358842559 )
                    __break(0x8228u);
                  if ( (((__int64 (__fastcall *)(_QWORD *, __int64))v19)(a1 - 9, v18) & 0x80000000) != 0 )
                  {
                    kfree(v18);
                  }
                  else
                  {
                    v20 = (_QWORD *)*v4;
                    v21 = v18 + 32;
                    if ( *(__int64 **)(*v4 + 8) != v4 || (__int64 *)v21 == v4 || v20 == (_QWORD *)v21 )
                    {
                      _list_add_valid_or_report(v21);
                    }
                    else
                    {
                      v20[1] = v21;
                      *(_QWORD *)(v18 + 32) = v20;
                      *(_QWORD *)(v18 + 40) = v4;
                      *v4 = v21;
                    }
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v5 = (_DWORD *)a1[16];
        v6 = a1[5];
        if ( v5 )
        {
          v7 = a1[5];
          if ( *(v5 - 1) != 1825338603 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, _QWORD *, __int64, _QWORD))v5)(a1 - 9, v61, v7, (int)v8);
        }
        else if ( (unsigned int)v8 <= 6 )
        {
          printk(&unk_8311, v10, v11);
        }
        else if ( *(_BYTE *)v6 == 2 )
        {
          mutex_lock(a1 + 22);
          v22 = idr_find(a1 + 19, *(unsigned __int16 *)(v6 + 1));
          if ( v22 )
          {
            v23 = *(_QWORD *)(v22 + 64);
            v24 = v22;
            if ( v23 && (v25 = *(_QWORD *)(v22 + 56)) != 0 )
            {
              v26 = qmi_decode_message(v6, (int)v8, v25, v23);
              if ( v26 < 0 )
              {
                v46 = v26;
                printk(&unk_82AC, v27, v28);
                v26 = v46;
              }
              *(_DWORD *)(v24 + 48) = v26;
              complete(v24 + 16);
            }
            else
            {
              qmi_invoke_handler(a1 - 9, v61, v22, v6, (int)v8);
            }
          }
          mutex_unlock(a1 + 22);
        }
        else
        {
          v70 = 0;
          v71 = 0;
          v68 = 0;
          v69 = 0;
          v66 = 0;
          v67 = 0;
          v64 = 0;
          v65 = 0;
          v63 = 0;
          LOWORD(v64) = *(_WORD *)(v6 + 1);
          qmi_invoke_handler(a1 - 9, v61, &v63, v6, (int)v8);
        }
      }
      mutex_lock(v1);
      if ( !*(a1 - 9) )
        goto LABEL_106;
    }
  }
  else
  {
LABEL_106:
    mutex_unlock(v1);
    v8 = -32;
LABEL_107:
    result = printk(&unk_841B, v8, v11);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
