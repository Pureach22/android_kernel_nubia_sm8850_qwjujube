__int64 __fastcall qrtr_gunyah_send(__int64 a1, __int64 a2)
{
  __int64 v2; // x26
  int v4; // w25
  int v5; // w24
  int v6; // w19
  unsigned __int64 v7; // x19
  unsigned int v8; // w9
  unsigned __int64 v9; // x8
  unsigned int v10; // w9
  unsigned __int64 v11; // x21
  unsigned int v12; // w8
  __int64 v13; // x0
  int v14; // w0
  unsigned __int64 v15; // x8
  unsigned int v16; // w10
  unsigned int v17; // w10
  __int64 i; // x23
  unsigned __int64 v19; // x8
  unsigned int v20; // w10
  unsigned __int64 v21; // x9
  unsigned int v22; // w10
  bool v23; // cc
  bool v24; // w8
  __int64 v25; // x0
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x22
  int v29; // w0
  unsigned __int64 v30; // x9
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x19
  int v33; // w23
  unsigned __int64 v34; // x21
  unsigned int v35; // w0
  __int64 v36; // x28
  __int64 v37; // x23
  unsigned int v38; // w24
  __int64 v39; // x28
  unsigned int v40; // w26
  int v41; // w28
  __int64 v42; // x23
  unsigned __int64 v43; // x24
  unsigned __int64 v44; // x8
  unsigned __int64 v45; // x9
  _DWORD *v46; // x10
  unsigned int v47; // w0
  __int64 v48; // x19
  __int64 v49; // x23
  unsigned int v50; // w24
  unsigned __int64 v51; // x21
  unsigned int v52; // w26
  __int64 v53; // x0
  int v54; // w0
  bool v55; // vf
  int v58; // [xsp+10h] [xbp-2B0h]
  int v59; // [xsp+10h] [xbp-2B0h]
  int v60; // [xsp+1Ch] [xbp-2A4h]
  unsigned __int64 v61; // [xsp+20h] [xbp-2A0h]
  __int64 v62; // [xsp+28h] [xbp-298h] BYREF
  __int64 v63; // [xsp+30h] [xbp-290h]
  unsigned __int64 v64; // [xsp+38h] [xbp-288h]
  __int64 v65; // [xsp+40h] [xbp-280h]
  __int64 v66; // [xsp+48h] [xbp-278h]
  __int64 v67; // [xsp+50h] [xbp-270h]
  __int64 v68; // [xsp+58h] [xbp-268h]
  __int64 v69; // [xsp+60h] [xbp-260h]
  __int64 v70; // [xsp+68h] [xbp-258h]
  _QWORD s[74]; // [xsp+70h] [xbp-250h] BYREF

  v2 = a2;
  s[72] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 112);
  if ( v4 >= 1 )
  {
    v5 = 0;
    v60 = 0;
    while ( 1 )
    {
      v7 = **(unsigned int **)(a1 + 328);
      v8 = **(_DWORD **)(a1 + 320);
      if ( v8 <= (unsigned int)v7 )
      {
        v26 = *(_QWORD *)(a1 + 352);
        v10 = v8 - v7 + v26;
        v11 = v26 - v7;
        if ( v26 < v7 )
          goto LABEL_32;
LABEL_6:
        v12 = v10 - 8;
        if ( v10 <= 8 )
          goto LABEL_7;
        if ( v12 >= v4 )
          v28 = (unsigned int)v4;
        else
          v28 = v12;
        if ( *(_DWORD *)(v2 + 116) )
        {
          memset(s, 0, 0x240u);
          sg_init_table(
            s,
            (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v2 + 216) + *(unsigned int *)(v2 + 212) + 2LL) + 1);
          v29 = skb_to_sgvec(v2, s, 0, *(unsigned int *)(v2 + 112));
          v60 = v29;
          if ( v29 < 0 )
          {
            dev_err(*(_QWORD *)(a1 + 24), "failed skb_to_sgvec rc:%d\n", v29);
            goto LABEL_91;
          }
          v30 = **(unsigned int **)(a1 + 328);
          v31 = *(_QWORD *)(a1 + 352);
          v32 = v31 - v30;
          v61 = v30;
          if ( v31 < v30 )
          {
            __break(0x800u);
            goto LABEL_79;
          }
          v33 = v5;
          if ( v32 >= v28 )
            v34 = v28;
          else
            v34 = v31 - v30;
          if ( v34 )
          {
            v35 = sg_nents(s);
            v36 = *(_QWORD *)(a1 + 344);
            v69 = 0;
            v70 = 0;
            v67 = 0;
            v68 = 0;
            v65 = 0;
            v66 = 0;
            v63 = 0;
            v64 = 0;
            v62 = 0;
            sg_miter_start(&v62, s, v35, 5);
            if ( (sg_miter_skip(&v62, v5) & 1) != 0 )
            {
              v58 = v5;
              v37 = 0;
              v38 = 0;
              v39 = v36 + v61;
              do
              {
                if ( (sg_miter_next(&v62) & 1) == 0 )
                  break;
                v40 = v64 >= v34 - v37 ? v34 - v37 : v64;
                _memcpy_toio(v39 + v37, v63, v40);
                v38 += v40;
                v37 = v38;
              }
              while ( v34 > v38 );
              sg_miter_stop(&v62);
              v2 = a2;
              v5 = v58;
            }
            else
            {
              LODWORD(v37) = 0;
            }
            v33 = v37 + v5;
          }
          if ( v32 < v28 )
          {
            v47 = sg_nents(s);
            v48 = *(_QWORD *)(a1 + 344);
            v69 = 0;
            v70 = 0;
            v67 = 0;
            v68 = 0;
            v65 = 0;
            v66 = 0;
            v63 = 0;
            v64 = 0;
            v62 = 0;
            sg_miter_start(&v62, s, v47, 5);
            if ( (sg_miter_skip(&v62, v33) & 1) != 0 )
            {
              v59 = v5;
              v49 = 0;
              v50 = 0;
              v51 = v28 - v34;
              do
              {
                if ( (sg_miter_next(&v62) & 1) == 0 )
                  break;
                v52 = v64 >= v51 - v49 ? v51 - v49 : v64;
                _memcpy_toio(v48 + v49, v63, v52);
                v50 += v52;
                v49 = v50;
              }
              while ( v51 > v50 );
              sg_miter_stop(&v62);
              v2 = a2;
              v5 = v59;
            }
          }
          v44 = *(_QWORD *)(a1 + 352);
          __dmb(0xAu);
          v46 = *(_DWORD **)(a1 + 328);
          v45 = (unsigned int)(v61 + v28);
        }
        else
        {
          v41 = v5;
          v42 = *(_QWORD *)(v2 + 224) + v5;
          if ( v11 >= v28 )
            v43 = v28;
          else
            v43 = v11;
          if ( v43 )
            _memcpy_toio(*(_QWORD *)(a1 + 344) + v7, v42, v43);
          if ( v11 < v28 )
            _memcpy_toio(*(_QWORD *)(a1 + 344), v42 + v43, v28 - v43);
          v44 = *(_QWORD *)(a1 + 352);
          v45 = (unsigned int)(v7 + v28);
          __dmb(0xAu);
          v46 = *(_DWORD **)(a1 + 328);
          v5 = v41;
        }
        if ( v44 > v45 )
          LODWORD(v44) = 0;
        *v46 = v45 - v44;
LABEL_79:
        v53 = *(_QWORD *)(a1 + 264);
        s[0] = 1;
        v54 = gh_dbl_send(v53, s, 0x100000000LL);
        if ( v54 )
        {
          if ( v54 != 11 )
          {
            dev_err(*(_QWORD *)(a1 + 24), "failed to raise doorbell %d\n", v54);
            if ( (*(_BYTE *)(a1 + 176) & 1) != 0 )
              goto LABEL_83;
LABEL_82:
            queue_work_on(32, system_wq, a1 + 280);
            goto LABEL_83;
          }
          if ( (*(_BYTE *)(a1 + 176) & 1) == 0 )
            goto LABEL_82;
        }
LABEL_83:
        v55 = __OFSUB__(v4, (_DWORD)v28);
        v4 -= v28;
        v5 += v28;
        if ( (v4 < 0) ^ v55 | (v4 == 0) )
          goto LABEL_91;
      }
      else
      {
        v9 = *(_QWORD *)(a1 + 352);
        v10 = v8 - v7;
        v11 = v9 - v7;
        if ( v9 >= v7 )
          goto LABEL_6;
LABEL_32:
        __break(0x800u);
LABEL_7:
        **(_DWORD **)(a1 + 336) = 1;
        v13 = *(_QWORD *)(a1 + 264);
        s[0] = 1;
        v14 = gh_dbl_send(v13, s, 0x100000000LL);
        if ( !v14 )
          goto LABEL_11;
        if ( v14 == 11 )
        {
          if ( (*(_BYTE *)(a1 + 176) & 1) != 0 )
            goto LABEL_11;
LABEL_10:
          queue_work_on(32, system_wq, a1 + 280);
          goto LABEL_11;
        }
        dev_err(*(_QWORD *)(a1 + 24), "failed to raise doorbell %d\n", v14);
        if ( (*(_BYTE *)(a1 + 176) & 1) == 0 )
          goto LABEL_10;
LABEL_11:
        v15 = **(unsigned int **)(a1 + 328);
        v16 = **(_DWORD **)(a1 + 320);
        if ( v16 <= (unsigned int)v15 )
        {
          v27 = *(_QWORD *)(a1 + 352);
          v17 = v16 - v15 + v27;
          if ( v27 < v15 )
          {
LABEL_34:
            __break(0x800u);
            goto LABEL_14;
          }
        }
        else
        {
          v17 = v16 - v15;
          if ( *(_QWORD *)(a1 + 352) < v15 )
            goto LABEL_34;
        }
        if ( v17 <= 8 )
        {
LABEL_14:
          memset(s, 0, 40);
          init_wait_entry(s, 0);
          for ( i = 2500; ; i = schedule_timeout() )
          {
            prepare_to_wait_event(a1 + 400, s, 2);
            v19 = **(unsigned int **)(a1 + 328);
            v20 = **(_DWORD **)(a1 + 320);
            if ( v20 > (unsigned int)v19 )
            {
              v21 = *(_QWORD *)(a1 + 352);
              v22 = v20 - v19;
              if ( v21 >= v19 )
                goto LABEL_19;
LABEL_17:
              __break(0x800u);
              goto LABEL_19;
            }
            v21 = *(_QWORD *)(a1 + 352);
            v22 = v20 - v19 + v21;
            if ( v21 < v19 )
              goto LABEL_17;
LABEL_19:
            v23 = v21 >= v19 && v22 > 8;
            v24 = v23;
            v25 = v24 && i == 0 ? 1LL : i;
            if ( v24 || !v25 )
              break;
          }
          v6 = v25;
          finish_wait(a1 + 400, s);
          if ( !v6 )
          {
            dev_err(*(_QWORD *)(a1 + 24), "transport stalled\n");
            v60 = -110;
            goto LABEL_91;
          }
        }
      }
    }
  }
  v60 = 0;
LABEL_91:
  **(_DWORD **)(a1 + 336) = 0;
  sk_skb_reason_drop(0, v2, 2);
  _ReadStatusReg(SP_EL0);
  return v60 & (unsigned int)(v60 >> 31);
}
