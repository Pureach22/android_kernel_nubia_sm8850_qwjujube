__int64 __fastcall pdr_locator_work(__int64 a1)
{
  __int64 v1; // x20
  int v3; // w19
  __int64 result; // x0
  _QWORD *v5; // x21
  _QWORD *v6; // x25
  _QWORD *v7; // t1
  __int64 v8; // x23
  _QWORD *v9; // x22
  unsigned __int64 v10; // x24
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x2
  int v13; // w28
  char *v14; // x26
  unsigned int v15; // w0
  unsigned int v16; // w19
  __int64 v17; // x3
  unsigned int v18; // w19
  __int64 v19; // x20
  __int64 v20; // x23
  unsigned int v21; // w8
  __int64 v22; // x8
  unsigned int v23; // w0
  unsigned int v24; // w19
  _QWORD *v25; // x8
  _QWORD *v26; // x9
  __int64 v27; // x0
  __int64 v28; // x2
  void (__fastcall *v29)(__int64, char *, __int64); // x8
  __int64 v30; // [xsp+10h] [xbp-E0h]
  __int64 v31; // [xsp+18h] [xbp-D8h]
  __int64 v32; // [xsp+20h] [xbp-D0h]
  _QWORD *v33; // [xsp+30h] [xbp-C0h]
  _QWORD *v34; // [xsp+38h] [xbp-B8h]
  __int64 v35; // [xsp+48h] [xbp-A8h]
  _QWORD v36[9]; // [xsp+50h] [xbp-A0h] BYREF
  _QWORD v37[8]; // [xsp+98h] [xbp-58h] BYREF
  __int64 v38; // [xsp+D8h] [xbp-18h]
  __int64 v39; // [xsp+E0h] [xbp-10h]

  v1 = a1 - 56;
  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 - 56);
  v3 = *(unsigned __int8 *)(a1 - 8);
  v35 = v1;
  result = mutex_unlock(v1);
  if ( v3 == 1 )
  {
    v31 = a1 - 152;
    mutex_lock(a1 - 152);
    v32 = a1;
    v7 = *(_QWORD **)(a1 - 184);
    v5 = (_QWORD *)(a1 - 184);
    v6 = v7;
    if ( v7 != v5 )
    {
      v8 = v32 - 808;
      v33 = v5;
      _ReadStatusReg(SP_EL0);
      v30 = v32 - 104;
      do
      {
        v9 = (_QWORD *)*v6;
        if ( *((_BYTE *)v6 - 2) == 1 )
        {
          v38 = 0;
          memset(v37, 0, sizeof(v37));
          v10 = _kmalloc_cache_noprof(servreg_restart_pd_resp_ei, 3520, 2452);
          v34 = v6 - 21;
          if ( !v10 )
          {
            v14 = (char *)v6 - 103;
            printk(&unk_7898, (char *)v6 - 103, v6 - 21, 4294967284LL);
LABEL_44:
            v25 = (_QWORD *)v6[1];
            if ( (_QWORD *)*v25 == v6 && (v26 = (_QWORD *)*v6, *(_QWORD **)(*v6 + 8LL) == v6) )
            {
              v26[1] = v25;
              *v25 = v26;
            }
            else
            {
              _list_del_entry_valid_or_report(v6);
            }
            *v6 = 0xDEAD000000000100LL;
            v6[1] = 0xDEAD000000000122LL;
            *((_DWORD *)v6 - 2) = 1;
            mutex_lock(v30);
            v27 = *((unsigned int *)v6 - 2);
            v29 = *(void (__fastcall **)(__int64, char *, __int64))(v32 + 112);
            v28 = *(_QWORD *)(v32 + 120);
            if ( *((_DWORD *)v29 - 1) != -1320911916 )
              __break(0x8228u);
            v29(v27, v14, v28);
            mutex_unlock(v30);
            kfree(v34);
            goto LABEL_5;
          }
          v11 = strnlen((const char *)v6 - 168, 0x41u);
          if ( v11 >= 0x42 )
            goto LABEL_56;
          if ( v11 == 65 )
            v12 = 65;
          else
            v12 = v11 + 1;
          if ( v12 >= 0x42 )
LABEL_57:
            _fortify_panic(7, 65, v12);
          sized_strscpy(v37, v6 - 21);
          v13 = 0;
          v14 = (char *)v6 - 103;
          BYTE1(v38) = 1;
          while ( 1 )
          {
            HIDWORD(v38) = v13;
            memset(v36, 0, sizeof(v36));
            v15 = qmi_txn_init(v8, v36, &servreg_get_domain_list_resp_ei, v10);
            if ( (v15 & 0x80000000) != 0 )
            {
              v16 = v15;
              goto LABEL_33;
            }
            mutex_lock(v35);
            v16 = qmi_send_request(v8, v32 - 200, v36, 33, 74, &servreg_get_domain_list_req_ei, v37);
            mutex_unlock(v35);
            if ( (v16 & 0x80000000) != 0 )
            {
              qmi_txn_cancel(v36);
              goto LABEL_33;
            }
            v11 = qmi_txn_wait(v36, 1250);
            if ( (v11 & 0x80000000) != 0 )
            {
              v16 = v11;
              printk(&unk_7911, v37, (unsigned int)v11, v17);
              goto LABEL_33;
            }
            if ( *(_WORD *)v10 )
              break;
            v18 = *(_DWORD *)(v10 + 16);
            v19 = v8;
            if ( v18 )
            {
              v20 = 0;
              while ( 1 )
              {
                if ( v20 == 2432 )
                  goto LABEL_55;
                v11 = strnlen((const char *)(v10 + v20 + 20), 0x41u);
                if ( v11 >= 0x42 )
                  goto LABEL_56;
                if ( v11 != 65 )
                {
                  v11 = strcmp((const char *)(v10 + v20 + 20), (const char *)v6 - 103);
                  if ( !(_DWORD)v11 )
                    break;
                }
                v20 += 76;
                if ( 76LL * v18 == v20 )
                  goto LABEL_27;
              }
              if ( (unsigned __int64)(v20 - 2368) >= 0xFFFFFFFFFFFFF66BLL )
              {
                *((_BYTE *)v6 - 16) = *(_BYTE *)(v10 + v20 + 85);
                if ( (unsigned __int64)(v20 - 2364) >= 0xFFFFFFFFFFFFF66CLL )
                {
                  *((_DWORD *)v6 - 3) = *(_DWORD *)(v10 + v20 + 88);
                  if ( (unsigned __int64)(v20 - 2360) >= 0xFFFFFFFFFFFFF66CLL )
                  {
                    v22 = v10 + v20;
                    v16 = 0;
                    v8 = v19;
                    *((_DWORD *)v6 - 6) = *(_DWORD *)(v22 + 92);
                    goto LABEL_33;
                  }
                }
              }
LABEL_55:
              __break(1u);
LABEL_56:
              _fortify_panic(2, 65, v11 + 1);
              goto LABEL_57;
            }
LABEL_27:
            v21 = *(unsigned __int16 *)(v10 + 6);
            if ( v18 > v21 )
            {
              v18 = *(unsigned __int16 *)(v10 + 6);
              *(_DWORD *)(v10 + 16) = v21;
            }
            v13 += v18;
            v8 = v19;
            if ( v13 >= (int)v21 )
            {
              v16 = -6;
              goto LABEL_33;
            }
          }
          printk(&unk_7940, v37, *(unsigned __int16 *)(v10 + 2), v17);
          v16 = -121;
LABEL_33:
          if ( v10 <= 0xFFFFFFFFFFFFF000LL )
            kfree(v10);
          if ( (v16 & 0x80000000) != 0 )
          {
            printk(&unk_7898, (char *)v6 - 103, v34, v16);
            v5 = v33;
            if ( v16 != -6 )
              goto LABEL_44;
          }
          else
          {
            v23 = qmi_add_lookup(v32 - 504, *((unsigned int *)v6 - 5), 1, *((unsigned int *)v6 - 6));
            if ( (v23 & 0x80000000) != 0 )
            {
              v24 = v23;
              printk(&unk_7898, (char *)v6 - 103, v34, v23);
              v5 = v33;
              if ( v24 != -6 )
                goto LABEL_44;
            }
            else
            {
              v5 = v33;
              *((_BYTE *)v6 - 2) = 0;
            }
          }
        }
LABEL_5:
        v6 = v9;
      }
      while ( v9 != v5 );
    }
    result = mutex_unlock(v31);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
