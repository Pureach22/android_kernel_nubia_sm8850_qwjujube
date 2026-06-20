__int64 __fastcall rndis_msg_parser(__int64 a1, int *a2)
{
  int v3; // w2
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x20
  __int64 v8; // x23
  int v9; // w21
  __int64 v10; // x0
  __int64 stats; // x0
  __int64 v12; // x8
  int v13; // w8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v19; // x0
  __int64 v20; // x8
  int v21; // w10
  int v22; // w9
  __int64 result; // x0
  unsigned int v24; // w22
  __int64 v26; // x0
  _DWORD *v27; // x21
  _DWORD *v28; // x23
  int v29; // t1
  int v30; // w2
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x8
  _QWORD **v34; // x20
  _QWORD *v35; // x23
  __int64 v36; // x23
  _QWORD *v37; // x0
  _QWORD *v38; // x9
  _QWORD *v39; // x24
  _QWORD *v40; // x8
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x8
  int v46; // w8
  int v47; // w9
  int v48; // w10
  __int64 v49; // x8
  unsigned int v50; // w21
  __int16 v51; // w9
  const char *v52; // x0
  __int64 v53; // x8
  __int64 v54; // x0
  void (__fastcall *v55)(_QWORD); // x8
  unsigned __int64 v62; // x9
  unsigned __int64 v65; // x9
  _QWORD v66[26]; // [xsp+0h] [xbp-D0h] BYREF

  v66[25] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_50;
  if ( !a1 )
    goto LABEL_58;
  v3 = *a2;
  if ( *a2 > 4 )
  {
    if ( v3 != 5 )
    {
      if ( v3 == 6 )
      {
        v34 = (_QWORD **)(a1 + 80);
LABEL_34:
        raw_spin_lock(a1 + 96);
        v35 = (_QWORD *)(a1 + 80);
        while ( 1 )
        {
          v35 = (_QWORD *)*v35;
          if ( v35 == v34 )
            break;
          if ( !*((_DWORD *)v35 + 7) )
          {
            *((_DWORD *)v35 + 7) = 1;
            raw_spin_unlock(a1 + 96);
            v36 = v35[2];
            if ( !v36 )
              goto LABEL_48;
            raw_spin_lock(a1 + 96);
            v37 = *v34;
            if ( *v34 != v34 )
            {
              do
              {
                v39 = (_QWORD *)*v37;
                if ( v37[2] == v36 )
                {
                  v40 = (_QWORD *)v37[1];
                  if ( (_QWORD *)*v40 == v37 && (_QWORD *)v39[1] == v37 )
                  {
                    v39[1] = v40;
                    *v40 = v39;
                  }
                  else
                  {
                    _list_del_entry_valid_or_report(v37);
                    v37 = v38;
                  }
                  *v37 = 0xDEAD000000000100LL;
                  v37[1] = 0xDEAD000000000122LL;
                  kfree(v37);
                }
                v37 = v39;
              }
              while ( v39 != v34 );
            }
            raw_spin_unlock(a1 + 96);
            goto LABEL_34;
          }
        }
        raw_spin_unlock(a1 + 96);
LABEL_48:
        v41 = rndis_add_response(a1, 16);
        if ( v41 )
        {
          v42 = *(_QWORD *)(v41 + 16);
          *(_QWORD *)(v42 + 4) = 16;
          *(_DWORD *)v42 = -2147483642;
          *(_DWORD *)(v42 + 12) = 1;
          goto LABEL_112;
        }
      }
      else
      {
        if ( v3 != 8 )
          goto LABEL_57;
        v15 = rndis_add_response(a1, 16);
        if ( v15 )
        {
          v16 = *(_QWORD *)(v15 + 16);
          *(_DWORD *)v16 = -2147483640;
          *(_DWORD *)(v16 + 4) = 16;
          *(_QWORD *)(v16 + 8) = (unsigned int)a2[2];
LABEL_112:
          v55 = *(void (__fastcall **)(_QWORD))(a1 + 64);
          v54 = *(_QWORD *)(a1 + 72);
          if ( *((_DWORD *)v55 - 1) != 251140989 )
            __break(0x8228u);
          v55(v54);
          goto LABEL_115;
        }
      }
LABEL_50:
      result = 4294967284LL;
      goto LABEL_116;
    }
    result = 4294967274LL;
    if ( (unsigned int)a2[4] > 0x616 )
      goto LABEL_116;
    v24 = a2[5];
    if ( v24 > 0x60D )
      goto LABEL_116;
    v26 = rndis_add_response(a1, 16);
    if ( !v26 )
      goto LABEL_50;
    v27 = *(_DWORD **)(v26 + 16);
    *v27 = -2147483643;
    v27[1] = 16;
    v29 = a2[2];
    v28 = a2 + 2;
    v27[2] = v29;
    if ( *(_QWORD *)(v26 + 16) )
    {
      v30 = v28[1];
      if ( v30 == 16843011 )
      {
LABEL_30:
        v27[3] = 0;
        goto LABEL_112;
      }
      if ( v30 == 65806 )
      {
        **(_WORD **)(a1 + 32) = *(_DWORD *)((char *)v28 + v24);
        if ( !**(_WORD **)(a1 + 32) )
        {
          v44 = *(_QWORD *)(a1 + 40);
          *(_DWORD *)(a1 + 8) = 1;
          netif_carrier_off(v44);
          v45 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
          *(_QWORD *)(v45 + 328) = jiffies;
          __dmb(0xBu);
          _X8 = (unsigned __int64 *)(v45 + 336);
          __asm { PRFM            #0x11, [X8] }
          do
            v65 = __ldxr(_X8);
          while ( __stxr(v65 | 1, _X8) );
          v27[3] = 0;
          goto LABEL_112;
        }
        v31 = *(_QWORD *)(a1 + 40);
        *(_DWORD *)(a1 + 8) = 2;
        netif_carrier_on(v31);
        v32 = *(_QWORD *)(a1 + 40);
        if ( (*(_QWORD *)(v32 + 168) & 1) != 0 )
        {
          netif_tx_wake_queue(*(_QWORD *)(v32 + 24));
          v27[3] = 0;
          goto LABEL_112;
        }
        goto LABEL_30;
      }
      printk(&unk_10FBC, "gen_ndis_set_resp");
    }
    v27[3] = -1073741637;
    goto LABEL_112;
  }
  if ( v3 == 2 )
  {
    v17 = *(_QWORD *)(a1 + 40);
    *(_DWORD *)(a1 + 8) = 1;
    if ( !v17 )
      goto LABEL_58;
    v19 = rndis_add_response(a1, 52);
    if ( v19 )
    {
      v20 = *(_QWORD *)(v19 + 16);
      *(_QWORD *)v20 = 0x3480000002LL;
      v21 = a2[2];
      *(_QWORD *)(v20 + 12) = 0x100000000LL;
      *(_QWORD *)(v20 + 20) = 0x100000000LL;
      *(_QWORD *)(v20 + 28) = 0x100000000LL;
      *(_DWORD *)(v20 + 8) = v21;
      v22 = *(_DWORD *)(*(_QWORD *)(a1 + 40) + 56LL);
      *(_QWORD *)(v20 + 40) = 0;
      *(_DWORD *)(v20 + 48) = 0;
      *(_DWORD *)(v20 + 36) = v22 + 80;
      goto LABEL_112;
    }
    goto LABEL_50;
  }
  if ( v3 != 3 )
  {
    if ( v3 == 4 )
    {
      if ( *(_QWORD *)(a1 + 40) )
      {
        v5 = rndis_add_response(a1, 136);
        if ( v5 )
        {
          v6 = *(_QWORD *)(v5 + 16);
          v7 = v5;
          *(_DWORD *)v6 = -2147483644;
          *(_DWORD *)(v6 + 8) = a2[2];
          v8 = *(_QWORD *)(v5 + 16);
          if ( !v8 )
          {
LABEL_103:
            *(_DWORD *)(v6 + 4) = 24;
            *(_QWORD *)(v6 + 12) = 3221225659LL;
            v53 = 20;
LABEL_111:
            *(_DWORD *)(v6 + v53) = 0;
            goto LABEL_112;
          }
          v9 = a2[3];
          memset(&v66[1], 0, 192);
          *(_DWORD *)(v8 + 20) = 16;
          v10 = *(_QWORD *)(a1 + 40);
          v66[0] = 0;
          stats = dev_get_stats(v10, v66);
          if ( v9 <= 66049 )
          {
            switch ( v9 )
            {
              case 65793:
                v50 = 112;
                *(_QWORD *)(v8 + 104) = 0x101010201010101LL;
                *(_QWORD *)(v8 + 112) = 0x101010501010103LL;
                *(_QWORD *)(v8 + 120) = 0x102010101010104LL;
                *(_QWORD *)(v8 + 128) = 0x102010301020102LL;
                *(_QWORD *)(v8 + 72) = 0x1011400010111LL;
                *(_QWORD *)(v8 + 80) = 0x2010100010202LL;
                *(_QWORD *)(v8 + 88) = 0x2010300020102LL;
                *(_QWORD *)(v8 + 96) = 0x2010500020104LL;
                *(_QWORD *)(v8 + 40) = 0x1010700010106LL;
                *(_QWORD *)(v8 + 48) = 0x1010B0001010ALL;
                *(_QWORD *)(v8 + 56) = 0x1010D0001010CLL;
                *(_QWORD *)(v8 + 64) = 0x1010E00010116LL;
                *(_QWORD *)(v8 + 24) = 0x1010200010101LL;
                *(_QWORD *)(v8 + 32) = 0x1010400010103LL;
                goto LABEL_110;
              case 65794:
                goto LABEL_92;
              case 65795:
              case 65796:
                v13 = *(_DWORD *)(a1 + 12);
                goto LABEL_108;
              case 65798:
              case 65802:
              case 65803:
                v12 = *(_QWORD *)(a1 + 40);
                if ( !v12 )
                  goto LABEL_102;
                v13 = *(_DWORD *)(v12 + 56);
                goto LABEL_108;
              case 65799:
                if ( *(_DWORD *)(a1 + 20) == 1 )
                  v13 = 0;
                else
                  v13 = *(_DWORD *)(a1 + 16);
                goto LABEL_108;
              case 65804:
                v13 = *(_DWORD *)(a1 + 48);
                goto LABEL_108;
              case 65805:
                v52 = *(const char **)(a1 + 56);
                if ( !v52 )
                  goto LABEL_92;
                v50 = strlen(v52);
                memcpy((void *)(v8 + 24), *(const void **)(a1 + 56), v50);
                goto LABEL_110;
              case 65806:
                v13 = **(unsigned __int16 **)(a1 + 32);
                goto LABEL_108;
              case 65809:
                v13 = 1558;
                goto LABEL_108;
              case 65811:
                v13 = 18;
                goto LABEL_108;
              case 65812:
                v13 = *(_DWORD *)(a1 + 20);
                goto LABEL_108;
              case 65814:
                goto LABEL_74;
              default:
                goto LABEL_81;
            }
          }
          if ( v9 > 16843009 )
          {
            if ( v9 <= 16843012 )
            {
              if ( v9 == 16843010 )
              {
LABEL_77:
                if ( *(_QWORD *)(a1 + 40) )
                {
                  v49 = *(_QWORD *)(a1 + 24);
                  v50 = 6;
                  v51 = *(_WORD *)(v49 + 4);
                  LODWORD(v49) = *(_DWORD *)v49;
                  *(_WORD *)(v8 + 28) = v51;
                  *(_DWORD *)(v8 + 24) = v49;
LABEL_110:
                  v53 = 12;
                  *(_DWORD *)(v8 + 16) = v50;
                  *(_DWORD *)(v7 + 24) = v50 + 24;
                  *(_DWORD *)(v8 + 4) = v50 + 24;
                  goto LABEL_111;
                }
                goto LABEL_102;
              }
              if ( v9 == 16843011 )
                v13 = -536870912;
              else
LABEL_74:
                v13 = 1;
LABEL_108:
              *(_DWORD *)(v8 + 24) = v13;
              goto LABEL_109;
            }
            if ( v9 > 16908545 )
            {
              if ( v9 != 16908546 && v9 != 16908547 )
                goto LABEL_81;
            }
            else if ( v9 != 16843013 )
            {
              if ( v9 == 16908545 )
              {
                if ( stats )
                {
                  v43 = *(_QWORD *)(stats + 104);
                  goto LABEL_98;
                }
                goto LABEL_102;
              }
              goto LABEL_81;
            }
          }
          else
          {
            if ( v9 > 131330 )
            {
              if ( v9 <= 131332 )
              {
                if ( v9 == 131331 )
                {
                  if ( stats )
                  {
                    v43 = *(_QWORD *)(stats + 40);
                    goto LABEL_98;
                  }
                }
                else if ( stats )
                {
                  v43 = *(_QWORD *)(stats + 32);
LABEL_98:
                  *(_DWORD *)(v8 + 24) = v43;
                  goto LABEL_109;
                }
                goto LABEL_102;
              }
              if ( v9 == 131333 )
              {
                if ( stats )
                {
                  v43 = *(_QWORD *)(stats + 48);
                  goto LABEL_98;
                }
                goto LABEL_102;
              }
              if ( v9 == 16843009 )
                goto LABEL_77;
              goto LABEL_81;
            }
            if ( v9 != 66050 )
            {
              if ( v9 == 131329 )
              {
                if ( !stats )
                  goto LABEL_102;
                v46 = *(_DWORD *)(stats + 40);
                v47 = *(_DWORD *)(stats + 56);
                v48 = *(_DWORD *)(stats + 8);
LABEL_101:
                v13 = v48 - (v46 + v47);
                goto LABEL_108;
              }
              if ( v9 == 131330 )
              {
                if ( !stats )
                {
LABEL_102:
                  *(_DWORD *)(v8 + 16) = 0;
                  *(_DWORD *)(v7 + 24) = 24;
                  *(_DWORD *)(v8 + 4) = 24;
                  goto LABEL_103;
                }
                v46 = *(_DWORD *)(stats + 32);
                v47 = *(_DWORD *)(stats + 48);
                v48 = *(_DWORD *)stats;
                goto LABEL_101;
              }
LABEL_81:
              printk(&unk_11D28, "gen_ndis_query_resp");
              goto LABEL_102;
            }
          }
LABEL_92:
          *(_DWORD *)(v8 + 24) = 0;
LABEL_109:
          v50 = 4;
          goto LABEL_110;
        }
        goto LABEL_50;
      }
LABEL_58:
      result = 4294966772LL;
      goto LABEL_116;
    }
LABEL_57:
    printk(&unk_1020B, "rndis_msg_parser");
    goto LABEL_58;
  }
  result = *(_QWORD *)(a1 + 40);
  *(_DWORD *)(a1 + 8) = 0;
  if ( result )
  {
    netif_carrier_off(result);
    v33 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
    *(_QWORD *)(v33 + 328) = jiffies;
    __dmb(0xBu);
    _X8 = (unsigned __int64 *)(v33 + 336);
    __asm { PRFM            #0x11, [X8] }
    do
      v62 = __ldxr(_X8);
    while ( __stxr(v62 | 1, _X8) );
LABEL_115:
    result = 0;
  }
LABEL_116:
  _ReadStatusReg(SP_EL0);
  return result;
}
