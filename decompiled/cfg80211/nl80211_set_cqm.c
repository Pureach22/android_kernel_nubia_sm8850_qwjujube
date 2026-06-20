__int64 __fastcall nl80211_set_cqm(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  _WORD *v3; // x2
  __int64 result; // x0
  _DWORD *v6; // x20
  __int64 v7; // x23
  int v8; // w9
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x19
  _BYTE *v11; // x21
  _QWORD *v12; // t2
  unsigned int v13; // w8
  unsigned int v14; // w27
  __int64 v15; // x26
  signed int v16; // w11
  int *v17; // x9
  __int64 v18; // x10
  int v19; // w12
  int v20; // t1
  int v21; // w9
  unsigned __int64 v22; // x22
  __int64 v23; // x25
  _DWORD *v24; // x0
  __int64 v25; // x1
  unsigned __int64 v26; // x24
  size_t v27; // x2
  bool v28; // w8
  unsigned int v29; // w19
  __int64 v30; // x1
  unsigned int v31; // w2
  unsigned int v32; // w3
  unsigned int v33; // w4
  unsigned __int64 StatusReg; // x24
  __int64 v35; // x19
  unsigned int v36; // w20
  __int64 v37; // x0
  __int64 v38; // x1
  __int64 v39; // x2
  __int64 v40; // x8
  __int64 v41; // [xsp+8h] [xbp-58h] BYREF
  _WORD *v42; // [xsp+10h] [xbp-50h]
  __int64 v43; // [xsp+18h] [xbp-48h]
  __int64 v44; // [xsp+20h] [xbp-40h]
  __int64 v45; // [xsp+28h] [xbp-38h]
  __int64 v46; // [xsp+30h] [xbp-30h]
  __int64 v47; // [xsp+38h] [xbp-28h]
  __int64 v48; // [xsp+40h] [xbp-20h]
  __int64 v49; // [xsp+48h] [xbp-18h]
  __int64 v50; // [xsp+50h] [xbp-10h]
  __int64 v51; // [xsp+58h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a2[4];
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = nullptr;
  v3 = *(_WORD **)(v2 + 752);
  if ( !v3 )
    goto LABEL_6;
  result = _nla_parse(&v41, 9, v3 + 2, (unsigned __int16)(*v3 - 4), &nl80211_attr_cqm_policy, 0, a2[8]);
  if ( !(_DWORD)result )
  {
    if ( v42 && v43 )
    {
      v6 = v42 + 2;
      if ( ((*v42 - 4) & 3) != 0 )
      {
LABEL_6:
        result = 4294967274LL;
        goto LABEL_7;
      }
      v12 = a2 + 6;
      v11 = (_BYTE *)a2[6];
      v10 = v12[1];
      v13 = (unsigned __int16)(*v42 - 4);
      v7 = *(unsigned int *)(v43 + 4);
      v14 = v13 >> 2;
      v15 = *(_QWORD *)(v10 + 992);
      if ( *v42 != 4 )
      {
        v16 = 0x80000000;
        v17 = (int *)(v42 + 2);
        v18 = v13 >> 2;
        result = 4294967274LL;
        do
        {
          v20 = *v17++;
          v19 = v20;
          if ( v20 > 0 || v19 <= v16 )
            goto LABEL_7;
          --v18;
          v16 = v19;
        }
        while ( v18 );
      }
      v21 = *(_DWORD *)(v15 + 8);
      if ( v21 == 8 || v21 == 2 )
      {
        if ( v13 == 4 )
          v14 = *v6 != 0;
        v22 = *(_QWORD *)(v15 + 208);
        if ( !v14 && !v22 )
          goto LABEL_30;
        if ( v14 >= 2 )
        {
          if ( (v11[1105] & 0x20) == 0 || !*(_QWORD *)(*(_QWORD *)v11 + 552LL) )
            goto LABEL_43;
LABEL_37:
          v23 = 4 * v14 + 40;
          v24 = (_DWORD *)_kmalloc_noprof(v23, 3520);
          v26 = (unsigned __int64)v24;
          if ( !v24 )
          {
            result = 4294967284LL;
            goto LABEL_7;
          }
          if ( (v23 & 0x1FFFC) == 0x10 || (v24[4] = v7, (v23 & 0x1FFFC) == 0x20) )
          {
            __break(1u);
          }
          else
          {
            v27 = 4 * v14;
            v25 = v23 - 36;
            v24[8] = v14;
            if ( v23 - 36 >= v27 )
            {
              memcpy(v24 + 9, v6, v27);
              v28 = v14 > 1 || *(_QWORD *)(*(_QWORD *)v11 + 544LL) == 0;
              *(_BYTE *)(v26 + 28) = v28;
              atomic_store(v26, (unsigned __int64 *)(v15 + 208));
              if ( *(_BYTE *)(v26 + 28) == 1 )
                result = cfg80211_cqm_rssi_update((__int64)v11, v10, (_DWORD *)v26);
              else
                result = rdev_set_cqm_rssi_config(v11, v10, (unsigned int)*v6, (unsigned int)v7);
LABEL_52:
              if ( (_DWORD)result )
              {
                atomic_store(v22, (unsigned __int64 *)(v15 + 208));
                if ( v26 )
                {
                  v29 = result;
                  kvfree_call_rcu(v26, v26);
                  result = v29;
                }
                goto LABEL_7;
              }
              if ( v22 )
                kvfree_call_rcu(v22, v22);
LABEL_30:
              result = 0;
              goto LABEL_7;
            }
          }
          _fortify_panic(17, v25);
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                           + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
              & 1) != 0 )
          {
            v35 = v30;
            v36 = v31;
            ++*(_DWORD *)(StatusReg + 16);
            v37 = _traceiter_rdev_set_cqm_txe_config(0, v7 + 992, v30, v31, v32, v33);
            v40 = *(_QWORD *)(StatusReg + 16) - 1LL;
            *(_DWORD *)(StatusReg + 16) = v40;
            if ( !v40 || (v38 = v35, v39 = v36, !*(_QWORD *)(StatusReg + 16)) )
              preempt_schedule_notrace(v37, v38, v39);
          }
LABEL_16:
          v9 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v7 + 560LL);
          if ( *((_DWORD *)v9 - 1) != -1780791122 )
            __break(0x8228u);
          result = v9(v7 + 992);
          goto LABEL_7;
        }
        if ( *(_QWORD *)(*(_QWORD *)v11 + 544LL) )
        {
          if ( !v14 )
          {
            *(_QWORD *)(v15 + 208) = 0;
            if ( *(_BYTE *)(v22 + 28) == 1 )
              result = rdev_set_cqm_rssi_range_config(v11, v10, 0, 0);
            else
              result = rdev_set_cqm_rssi_config(v11, v10, 0, 0);
            v26 = 0;
            goto LABEL_52;
          }
          goto LABEL_37;
        }
      }
    }
    else
    {
      result = 4294967274LL;
      if ( !v46 || !v47 || !v48 || *(_DWORD *)(v46 + 4) > 0x64u || *(_DWORD *)(v48 + 4) > 0x708u )
        goto LABEL_7;
      v7 = a2[6];
      if ( *(_QWORD *)(*(_QWORD *)v7 + 560LL) )
      {
        v8 = *(_DWORD *)(*(_QWORD *)(a2[7] + 992LL) + 8LL);
        if ( v8 == 8 || v8 == 2 )
          goto LABEL_16;
      }
    }
LABEL_43:
    result = 4294967201LL;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
