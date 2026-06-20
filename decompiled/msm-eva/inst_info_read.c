__int64 __fastcall inst_info_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *v4; // x8
  __int64 v5; // x24
  __int64 v6; // x19
  _QWORD *v7; // x9
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x1
  __int64 v11; // x2
  void *v12; // x0
  unsigned int v13; // w8
  unsigned int v15; // w20
  unsigned int v21; // w9
  unsigned __int64 v22; // x8
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x24
  __int64 v33; // x20
  unsigned int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x26
  const char *v44; // x4
  __int64 v45; // x26
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x25
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x25
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x25
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x25
  __int64 v82; // x26
  __int64 v83; // x23
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  const char *v92; // x4
  __int64 v93; // x3
  __int64 v94; // x21
  unsigned __int64 v95; // x8
  int v97; // w8

  v4 = *(_QWORD **)(a1 + 32);
  if ( v4 )
  {
    v5 = *v4;
    if ( *v4 )
    {
      v6 = v4[1];
      if ( v6 )
      {
        mutex_lock(*v4);
        v7 = (_QWORD *)(v5 + 280);
        do
          v7 = (_QWORD *)*v7;
        while ( v7 != (_QWORD *)(v5 + 280) && v7 != (_QWORD *)v6 );
        if ( v7 != (_QWORD *)v6 )
        {
LABEL_8:
          mutex_unlock(v5);
          result = 0;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            v10 = *(unsigned int *)(StatusReg + 1800);
            v11 = *(unsigned int *)(StatusReg + 1804);
            v12 = &unk_847E3;
LABEL_23:
            printk(v12, v10, v11, &unk_8E7CE);
            return 0;
          }
          return result;
        }
        v13 = *(_DWORD *)(v6 + 14824);
        _X22 = (unsigned int *)(v6 + 14824);
        if ( v13 )
        {
          do
          {
            __asm { PRFM            #0x11, [X22] }
            do
              v21 = __ldxr(_X22);
            while ( v21 == v13 && __stxr(v13 + 1, _X22) );
            v15 = v13;
            if ( v21 == v13 )
              break;
            v15 = 0;
            v13 = v21;
          }
          while ( v21 );
        }
        else
        {
          v15 = 0;
        }
        if ( (((v15 + 1) | v15) & 0x80000000) != 0 )
        {
          refcount_warn_saturate(v6 + 14824, 0);
          if ( !v15 )
            goto LABEL_8;
        }
        else if ( !v15 )
        {
          goto LABEL_8;
        }
        mutex_unlock(v5);
        v23 = _kmalloc_cache_noprof(_kmalloc_large_noprof, 3520, 4096);
        v32 = v23;
        if ( v23 )
        {
          v33 = v23 + 4096;
          v34 = write_str(v23, 4096, "==============================\n", v24, v25, v26, v27, v28, v29, v30, v31);
          v43 = v32 + v34;
          if ( *(_DWORD *)(v6 + 136) == 1 )
            v44 = "User";
          else
            v44 = "Kernel";
          v45 = v43
              + (unsigned int)write_str(
                                v43,
                                4096LL - v34,
                                "INSTANCE: %pK (%s)\n",
                                v35,
                                v36,
                                v37,
                                v38,
                                v39,
                                v40,
                                v41,
                                v42,
                                v6,
                                v44);
          v54 = v45
              + (unsigned int)write_str(
                                v45,
                                v33 - v45,
                                "==============================\n",
                                v46,
                                v47,
                                v48,
                                v49,
                                v50,
                                v51,
                                v52,
                                v53);
          v63 = v54
              + (unsigned int)write_str(
                                v54,
                                v33 - v54,
                                "core: %pK\n",
                                v55,
                                v56,
                                v57,
                                v58,
                                v59,
                                v60,
                                v61,
                                v62,
                                *(_QWORD *)(v6 + 128));
          v72 = v63
              + (unsigned int)write_str(
                                v63,
                                v33 - v63,
                                "state: %d\n",
                                v64,
                                v65,
                                v66,
                                v67,
                                v68,
                                v69,
                                v70,
                                v71,
                                *(unsigned int *)(v6 + 328));
          v81 = v72
              + (unsigned int)write_str(
                                v72,
                                v33 - v72,
                                "secure: %d\n",
                                v73,
                                v74,
                                v75,
                                v76,
                                v77,
                                v78,
                                v79,
                                v80,
                                *(_DWORD *)(v6 + 14088) & 1);
          v82 = v6 + 12936;
          v83 = -19;
          do
          {
            if ( (completion_done(v82) & 1) != 0 )
              v92 = "pending";
            else
              v92 = "done";
            v81 += (unsigned int)write_str(
                                   v81,
                                   v33 - v81,
                                   "completions[%d]: %s\n",
                                   v84,
                                   v85,
                                   v86,
                                   v87,
                                   v88,
                                   v89,
                                   v90,
                                   v91,
                                   (unsigned int)(v83 + 29),
                                   v92);
            _CF = __CFADD__(v83++, 1);
            v82 += 32;
          }
          while ( !_CF );
          if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
            printk(&unk_8FAA7, "sess", "publish_unreleased_reference", v93);
          v94 = simple_read_from_buffer(a2, a3, a4, v32, v81 - v32);
          kfree(v32);
          _X22 = (unsigned int *)(v6 + 14824);
        }
        else
        {
          v94 = -12;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v95 = _ReadStatusReg(SP_EL0);
            printk(&unk_847A4, *(unsigned int *)(v95 + 1800), *(unsigned int *)(v95 + 1804), &unk_8E7CE);
          }
        }
        __asm { PRFM            #0x11, [X22] }
        do
          v97 = __ldxr(_X22);
        while ( __stlxr(v97 - 1, _X22) );
        if ( v97 == 1 )
        {
          __dmb(9u);
          msm_cvp_destroy((__int64 *)v6);
        }
        else if ( v97 <= 0 )
        {
          refcount_warn_saturate(_X22, 3);
        }
        return v94;
      }
    }
  }
  result = 0;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v22 = _ReadStatusReg(SP_EL0);
    v10 = *(unsigned int *)(v22 + 1800);
    v11 = *(unsigned int *)(v22 + 1804);
    v12 = &unk_9307C;
    goto LABEL_23;
  }
  return result;
}
