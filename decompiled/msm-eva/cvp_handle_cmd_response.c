void __fastcall cvp_handle_cmd_response(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w19
  __int64 v5; // x20
  __int64 *v6; // x0
  int v7; // w4
  int v8; // w8
  __int64 *v9; // x19
  __int64 v10; // x0
  __int64 v11; // x22
  int v12; // w21
  __int64 v13; // x20
  __int64 *v14; // x0
  int v15; // w4
  int v16; // w8
  __int64 v17; // x24
  char *v18; // x25
  int v19; // w10
  int v20; // w8
  __int64 *inst; // x0
  __int64 v22; // x8
  __int64 v23; // x24
  __int64 *v24; // x0
  int v25; // w25
  __int64 *v26; // x26
  __int64 v27; // x3
  __int64 v28; // x27
  __int64 v29; // x2
  int v30; // w8
  __int64 v31; // x20
  __int64 v32; // x19
  __int64 v33; // x8
  unsigned __int64 v34; // x8
  __int64 *v35; // x19
  __int64 v36; // x19
  unsigned int v37; // w8
  int v38; // w10
  void *v39; // x0
  int v40; // w11
  int v41; // w8
  __int64 v42; // x8
  __int64 *v43; // x0
  __int64 v44; // x0
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x8
  __int64 v47; // x19
  int v48; // w4
  unsigned int v49; // w19
  __int64 v50; // x20
  unsigned __int64 v51; // x8
  __int64 v52; // x1
  __int64 v53; // x2
  void *v54; // x0
  _QWORD *v55; // x1
  __int64 v56; // x19
  _QWORD *v57; // x20
  int v58; // w4
  unsigned __int64 v59; // x8
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x8
  unsigned __int64 v62; // x8
  unsigned __int64 v63; // x8
  unsigned __int64 v64; // x8
  unsigned __int64 v65; // x8
  _QWORD *v66; // x20
  _QWORD *i; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v69; // x8
  unsigned __int64 v70; // x8
  unsigned __int64 v71; // x8
  __int64 v72; // x9
  __int64 *v73; // x20
  __int64 v74; // x21
  unsigned __int64 v75; // x8
  unsigned __int64 v76; // x8
  unsigned __int64 v77; // x8
  unsigned __int64 v78; // x8
  __int64 v79; // x9
  __int64 *v80; // x19
  __int64 v81; // x20
  unsigned __int64 v82; // x8

  if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
  {
    v49 = a1;
    v50 = a2;
    printk(&unk_91992, "hfi", (unsigned int)a1, a4);
    a1 = v49;
    a2 = v50;
  }
  switch ( (int)a1 )
  {
    case 1:
      if ( a2 )
      {
        v36 = *(_QWORD *)(cvp_driver + 48);
        if ( v36 )
        {
          v37 = *(_DWORD *)(a2 + 48);
          v38 = *(_DWORD *)(v36 + 1020);
          v39 = *(void **)(v36 + 1096);
          if ( v37 >= 0x20 )
            v40 = 32;
          else
            v40 = *(_DWORD *)(a2 + 48);
          if ( v37 )
            v41 = v40;
          else
            v41 = 32;
          *(_DWORD *)(v36 + 1016) = v41;
          if ( v38 )
            v41 = v38;
          *(_DWORD *)(v36 + 1020) = v41;
          memcpy(v39, *(const void **)(a2 + 40), 732LL * *(unsigned int *)(a2 + 32));
          if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
            printk(&unk_8B6D5, "core", "handle_sys_init_done", *(unsigned int *)(v36 + 1016));
          complete(v36 + 312);
        }
        else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          goto LABEL_141;
        }
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        goto LABEL_117;
      }
      return;
    case 3:
      if ( a2 )
      {
        v42 = *(_QWORD *)(cvp_driver + 48);
        if ( v42 )
        {
          complete(v42 + 376);
        }
        else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
LABEL_141:
          StatusReg = _ReadStatusReg(SP_EL0);
          v52 = *(unsigned int *)(StatusReg + 1800);
          v53 = *(unsigned int *)(StatusReg + 1804);
          v54 = &unk_95C93;
          goto LABEL_142;
        }
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
LABEL_117:
        v62 = _ReadStatusReg(SP_EL0);
        v52 = *(unsigned int *)(v62 + 1800);
        v53 = *(unsigned int *)(v62 + 1804);
        v54 = &unk_9265F;
        goto LABEL_142;
      }
      return;
    case 8:
    case 9:
      handle_sys_error(a1, a2);
      return;
    case 10:
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        v46 = _ReadStatusReg(SP_EL0);
        printk(&unk_95D0D, *(unsigned int *)(v46 + 1800), *(unsigned int *)(v46 + 1804), "warn");
      }
      return;
    case 11:
      if ( a2 )
      {
        v31 = a2;
        v32 = *(_QWORD *)(cvp_driver + 48);
        inst = cvp_get_inst(v32, *(__int64 **)(a2 + 8));
        if ( inst )
        {
          v33 = v31;
          if ( *(_DWORD *)(v31 + 16) )
          {
            if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
              goto LABEL_153;
            v34 = _ReadStatusReg(SP_EL0);
            v35 = inst;
            printk(&unk_9335F, *(unsigned int *)(v34 + 1800), *(unsigned int *)(v34 + 1804), &unk_8E7CE);
          }
          else
          {
            if ( (msm_cvp_debug & 0x2000) == 0 || msm_cvp_debug_out )
              goto LABEL_153;
            v35 = inst;
            printk(
              &unk_90D64,
              "sess",
              "handle_session_init_done",
              (unsigned int)(*((_DWORD *)inst + 81) ^ *((_DWORD *)inst + 80)));
          }
          inst = v35;
          v33 = v31;
LABEL_153:
          *((_DWORD *)inst + 3813) = *(_DWORD *)(v33 + 16);
          v22 = 1621;
          goto LABEL_154;
        }
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          v82 = _ReadStatusReg(SP_EL0);
          printk(&unk_829C1, *(unsigned int *)(v82 + 1800), *(unsigned int *)(v82 + 1804), "warn");
        }
        v66 = *(_QWORD **)(v32 + 280);
        for ( i = (_QWORD *)(v32 + 280); v66 != i; v66 = (_QWORD *)*v66 )
          cvp_print_inst(2, (__int64)v66);
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v61 = _ReadStatusReg(SP_EL0);
        v52 = *(unsigned int *)(v61 + 1800);
        v53 = *(unsigned int *)(v61 + 1804);
        v54 = &unk_89807;
        goto LABEL_142;
      }
      return;
    case 12:
    case 14:
      if ( a2 )
      {
        v11 = a2;
        v12 = a1;
        v13 = *(_QWORD *)(cvp_driver + 48);
        v14 = cvp_get_inst(v13, *(__int64 **)(a2 + 8));
        if ( v14 )
        {
          v15 = *(_DWORD *)(v11 + 16);
          v9 = v14;
          v16 = v12;
          if ( v15 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v75 = _ReadStatusReg(SP_EL0);
            printk(&unk_88F83, *(unsigned int *)(v75 + 1800), *(unsigned int *)(v75 + 1804), &unk_8E7CE);
            v15 = *(_DWORD *)(v11 + 16);
            v16 = v12;
          }
          *((_DWORD *)v9 + 3813) = v15;
          complete(&v9[4 * (unsigned int)(v16 - 10) + 1617]);
          v17 = 0;
          v18 = (char *)v9 + 13596;
          do
          {
            if ( v18[v17] )
            {
              if ( (msm_cvp_debug & 0x10) != 0 )
              {
                v19 = *((_DWORD *)v9 + 3502);
                v20 = msm_cvp_debug_out;
                if ( !v19
                  || msm_cvp_debug_out
                  || (printk(&unk_919EC, "prof", &v18[v17], (unsigned int)(*(_DWORD *)((char *)v9 + v17 + 13592) / v19)),
                      v20 = msm_cvp_debug_out,
                      (msm_cvp_debug & 0x10) != 0) )
                {
                  if ( !v20 )
                    printk(&unk_90DCC, "prof", &v18[v17], *((unsigned int *)v9 + 3502));
                }
              }
            }
            v17 += 84;
          }
          while ( v17 != 420 );
          goto LABEL_156;
        }
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          v76 = _ReadStatusReg(SP_EL0);
          printk(&unk_8AC75, *(unsigned int *)(v76 + 1800), *(unsigned int *)(v76 + 1804), "warn");
        }
        v55 = *(_QWORD **)(v13 + 280);
        v56 = v13 + 280;
        if ( v55 != (_QWORD *)(v13 + 280) )
        {
          do
          {
            v57 = (_QWORD *)*v55;
            cvp_print_inst(2, (__int64)v55);
            v55 = v57;
          }
          while ( v57 != (_QWORD *)v56 );
        }
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v51 = _ReadStatusReg(SP_EL0);
        v52 = *(unsigned int *)(v51 + 1800);
        v53 = *(unsigned int *)(v51 + 1804);
        v54 = &unk_95CC5;
        goto LABEL_142;
      }
      return;
    case 13:
      if ( a2 )
      {
        v47 = a2;
        inst = cvp_get_inst(*(_QWORD *)(cvp_driver + 48), *(__int64 **)(a2 + 8));
        if ( inst )
        {
          v48 = *(_DWORD *)(v47 + 16);
          if ( v48 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v78 = _ReadStatusReg(SP_EL0);
            v79 = v47;
            v80 = inst;
            v81 = v79;
            printk(&unk_8CA09, *(unsigned int *)(v78 + 1800), *(unsigned int *)(v78 + 1804), &unk_8E7CE);
            v48 = *(_DWORD *)(v81 + 16);
            inst = v80;
          }
          *((_DWORD *)inst + 3813) = v48;
          v22 = 1629;
          goto LABEL_154;
        }
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          v70 = _ReadStatusReg(SP_EL0);
          printk(&unk_8C9CB, *(unsigned int *)(v70 + 1800), *(unsigned int *)(v70 + 1804), "warn");
        }
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v64 = _ReadStatusReg(SP_EL0);
        v52 = *(unsigned int *)(v64 + 1800);
        v53 = *(unsigned int *)(v64 + 1804);
        v54 = &unk_85AEA;
        goto LABEL_142;
      }
      return;
    case 15:
    case 16:
    case 18:
      if ( !a2 )
      {
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          return;
        goto LABEL_105;
      }
      v4 = a1;
      v5 = a2;
      v6 = cvp_get_inst(*(_QWORD *)(cvp_driver + 48), *(__int64 **)(a2 + 8));
      if ( v6 )
      {
        v7 = *(_DWORD *)(v5 + 16);
        v8 = v4;
        if ( v7 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v71 = _ReadStatusReg(SP_EL0);
          v72 = v5;
          v73 = v6;
          v74 = v72;
          printk(&unk_90E00, *(unsigned int *)(v71 + 1800), *(unsigned int *)(v71 + 1804), &unk_8E7CE);
          v7 = *(_DWORD *)(v74 + 16);
          v6 = v73;
          v8 = v4;
        }
        *((_DWORD *)v6 + 3813) = v7;
        v9 = v6;
        v10 = (__int64)&v6[4 * (unsigned int)(v8 - 10) + 1617];
        goto LABEL_155;
      }
      if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
        return;
      goto LABEL_145;
    case 23:
      if ( a2 )
      {
        v23 = a2;
        v24 = cvp_get_inst(*(_QWORD *)(cvp_driver + 48), *(__int64 **)(a2 + 8));
        if ( v24 )
        {
          v9 = v24;
          v25 = *(_DWORD *)(v23 + 24);
          v26 = v24 + 50;
          mutex_lock(v24 + 52);
          v28 = v9[50];
          while ( (__int64 *)v28 != v26 )
          {
            v29 = *(unsigned int *)(*(_QWORD *)(v28 + 56) + 64LL);
            v30 = *(_DWORD *)(v28 + 24);
            v28 = *(_QWORD *)v28;
            if ( v25 == v30 + (_DWORD)v29 && (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
              printk(&unk_8ACF2, "sess", v29, v27);
          }
          mutex_unlock(v9 + 52);
          v58 = *(_DWORD *)(v23 + 16);
          if ( v58 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v77 = _ReadStatusReg(SP_EL0);
            printk(&unk_91A2A, *(unsigned int *)(v77 + 1800), *(unsigned int *)(v77 + 1804), &unk_8E7CE);
            v58 = *(_DWORD *)(v23 + 16);
          }
          *((_DWORD *)v9 + 3813) = v58;
          v10 = (__int64)(v9 + 1669);
          goto LABEL_155;
        }
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          v65 = _ReadStatusReg(SP_EL0);
          printk(&unk_90E3B, *(unsigned int *)(v65 + 1800), *(unsigned int *)(v65 + 1804), "warn");
        }
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v60 = _ReadStatusReg(SP_EL0);
        v52 = *(unsigned int *)(v60 + 1800);
        v53 = *(unsigned int *)(v60 + 1804);
        v54 = &unk_8ACB7;
        goto LABEL_142;
      }
      return;
    case 26:
      if ( !a2 )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
LABEL_105:
          v59 = _ReadStatusReg(SP_EL0);
          v52 = *(unsigned int *)(v59 + 1800);
          v53 = *(unsigned int *)(v59 + 1804);
          v54 = &unk_86FAA;
          goto LABEL_142;
        }
        return;
      }
      inst = cvp_get_inst(*(_QWORD *)(cvp_driver + 48), *(__int64 **)(a2 + 8));
      if ( inst )
      {
        v22 = 1681;
LABEL_154:
        v9 = inst;
        v10 = (__int64)&inst[v22];
LABEL_155:
        complete(v10);
        goto LABEL_156;
      }
      if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
        return;
      goto LABEL_145;
    case 28:
      if ( a2 )
      {
        v43 = cvp_get_inst(*(_QWORD *)(cvp_driver + 48), *(__int64 **)(a2 + 8));
        if ( v43 )
        {
          v9 = v43;
          v44 = raw_spin_lock_irqsave(v43 + 36);
          *((_DWORD *)v9 + 73) = 6;
          raw_spin_unlock_irqrestore(v9 + 36, v44);
          _wake_up(v9 + 37, 3, 0, 0);
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v45 = _ReadStatusReg(SP_EL0);
            printk(&unk_8700D, *(unsigned int *)(v45 + 1800), *(unsigned int *)(v45 + 1804), &unk_8E7CE);
          }
LABEL_156:
          cvp_put_inst((unsigned int *)v9);
        }
        else if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
LABEL_145:
          v69 = _ReadStatusReg(SP_EL0);
          printk(&unk_90D89, *(unsigned int *)(v69 + 1800), *(unsigned int *)(v69 + 1804), "warn");
        }
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v63 = _ReadStatusReg(SP_EL0);
        v52 = *(unsigned int *)(v63 + 1800);
        v53 = *(unsigned int *)(v63 + 1804);
        v54 = &unk_93DE1;
LABEL_142:
        printk(v54, v52, v53, &unk_8E7CE);
      }
      return;
    case 29:
      handle_session_error(a1, a2);
      return;
    default:
      if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
        printk(&unk_8EE6D, "hfi", (unsigned int)a1, a4);
      return;
  }
}
