__int64 __fastcall session_info_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  __int64 v5; // x27
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 *v14; // x24
  __int64 *v15; // x28
  __int64 v16; // x21
  __int64 v17; // x27
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x4
  __int64 v27; // x27
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x27
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x27
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x27
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x27
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x27
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x27
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int v98; // w0
  __int64 *i; // x22
  __int64 result; // x0
  unsigned __int64 v101; // x8
  __int64 v102; // x0
  __int64 v103; // x19
  __int64 *j; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v106; // [xsp+8h] [xbp-28h]
  __int64 v110; // [xsp+28h] [xbp-8h]

  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 && *(_QWORD *)(v4 + 256) )
  {
    v5 = _kmalloc_large_noprof(0x4000, 3520);
    if ( v5 )
    {
      mutex_lock(v4);
      v14 = *(__int64 **)(v4 + 280);
      v15 = (__int64 *)(v4 + 280);
      v106 = v4;
      v110 = v5;
      if ( v14 != (__int64 *)(v4 + 280) )
      {
        v16 = v5 + 0x4000;
        do
        {
          v17 = v5
              + (unsigned int)write_str(
                                v5,
                                v16 - v5,
                                "==============================\n",
                                v6,
                                v7,
                                v8,
                                v9,
                                v10,
                                v11,
                                v12,
                                v13);
          if ( *((_DWORD *)v14 + 34) == 1 )
            v26 = "User";
          else
            v26 = "Kernel";
          v27 = v17
              + (unsigned int)write_str(
                                v17,
                                v16 - v17,
                                "INSTANCE: %pK (%s)\n",
                                v18,
                                v19,
                                v20,
                                v21,
                                v22,
                                v23,
                                v24,
                                v25,
                                v14,
                                v26);
          v36 = v27
              + (unsigned int)write_str(
                                v27,
                                v16 - v27,
                                "proc name: %s\n",
                                v28,
                                v29,
                                v30,
                                v31,
                                v32,
                                v33,
                                v34,
                                v35,
                                v14 + 1924);
          v45 = v36
              + (unsigned int)write_str(
                                v36,
                                v16 - v36,
                                "session name: %s\n",
                                v37,
                                v38,
                                v39,
                                v40,
                                v41,
                                v42,
                                v43,
                                v44,
                                (char *)v14 + 14996);
          v54 = v45
              + (unsigned int)write_str(
                                v45,
                                v16 - v45,
                                "session id: %#x\n",
                                v46,
                                v47,
                                v48,
                                v49,
                                v50,
                                v51,
                                v52,
                                v53,
                                (unsigned int)(*((_DWORD *)v14 + 81) ^ *((_DWORD *)v14 + 80)));
          v63 = v54
              + (unsigned int)write_str(
                                v54,
                                v16 - v54,
                                "is secure: %u\n",
                                v55,
                                v56,
                                v57,
                                v58,
                                v59,
                                v60,
                                v61,
                                v62,
                                *((unsigned int *)v14 + 3710));
          v72 = v63
              + (unsigned int)write_str(
                                v63,
                                v16 - v63,
                                "priority: %u\n",
                                v64,
                                v65,
                                v66,
                                v67,
                                v68,
                                v69,
                                v70,
                                v71,
                                *((unsigned int *)v14 + 3709));
          v81 = v72
              + (unsigned int)write_str(
                                v72,
                                v16 - v72,
                                "qos latency: %u\n",
                                v73,
                                v74,
                                v75,
                                v76,
                                v77,
                                v78,
                                v79,
                                v80,
                                *((unsigned int *)v14 + 3852));
          v5 = v81
             + (unsigned int)write_str(
                               v81,
                               v16 - v81,
                               "state: %d\n",
                               v82,
                               v83,
                               v84,
                               v85,
                               v86,
                               v87,
                               v88,
                               v89,
                               *((unsigned int *)v14 + 82));
          v98 = write_str(
                  v5,
                  v16 - v5,
                  "total internal memory size: %d bytes\n",
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  v97,
                  *((unsigned int *)v14 + 132));
          for ( i = (__int64 *)v14[58]; ; i = (__int64 *)*i )
          {
            v5 += v98;
            if ( i == v14 + 58 )
              break;
            v98 = write_str(
                    v5,
                    v16 - v5,
                    "%s size: %d bytes\n",
                    v6,
                    v7,
                    v8,
                    v9,
                    v10,
                    v11,
                    v12,
                    v13,
                    i + 8,
                    *((unsigned int *)i + 21));
          }
          v14 = (__int64 *)*v14;
        }
        while ( v14 != v15 );
      }
      mutex_unlock(v106);
      v102 = simple_read_from_buffer(a2, a3, a4, v110, v5 - v110);
      v103 = v102;
      if ( (msm_cvp_debug & 0xEFE8) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8EF73, &unk_94624, "session_info_read", v102);
        if ( !v103 )
          goto LABEL_19;
      }
      else if ( !v102 )
      {
LABEL_19:
        mutex_lock(v106);
        for ( j = *(__int64 **)(v106 + 280); j != v15; j = (__int64 *)*j )
          cvp_print_inst(1, (__int64)j);
        mutex_unlock(v106);
      }
      kfree(v110);
      return v103;
    }
    result = -12;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_847A4, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return -12;
    }
  }
  else
  {
    result = 0;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v101 = _ReadStatusReg(SP_EL0);
      printk(&unk_8E291, *(unsigned int *)(v101 + 1800), *(unsigned int *)(v101 + 1804), &unk_8E7CE);
      return 0;
    }
  }
  return result;
}
