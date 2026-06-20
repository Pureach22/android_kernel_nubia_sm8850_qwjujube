__int64 __fastcall calibration_save_ois_dw9785(_QWORD *a1)
{
  int v2; // w1
  int v3; // w2
  int v4; // w1
  int v5; // w2
  int v6; // w1
  int v7; // w2
  int v8; // w1
  int v9; // w2
  int v10; // w1
  int v11; // w2
  int v12; // w1
  int v13; // w2
  int v14; // w1
  int v15; // w2
  int v16; // w1
  int v17; // w2
  int v18; // w1
  int v19; // w2
  int v20; // w1
  int v21; // w2
  int v22; // w1
  int v23; // w2
  int v24; // w1
  int v25; // w2
  int v26; // w1
  int v27; // w2
  int v28; // w1
  int v29; // w2
  int v30; // w1
  int v31; // w2
  int v32; // w1
  int v33; // w2
  int v34; // w1
  int v35; // w2
  int v36; // w1
  int v37; // w2
  int v38; // w1
  int v39; // w2
  int v40; // w1
  int v41; // w2
  int v42; // w1
  int v43; // w2
  int v44; // w1
  int v45; // w2
  int v46; // w1
  int v47; // w2
  int v48; // w1
  int v49; // w2
  int v50; // w1
  int v51; // w2
  int v52; // w1
  int v53; // w2
  int v54; // w1
  int v55; // w2
  int v56; // w1
  int v57; // w2
  int v58; // w1
  int v59; // w2
  int v60; // w1
  int v61; // w2
  int v62; // w1
  int v63; // w2
  int v64; // w1
  int v65; // w2
  int v66; // w1
  int v67; // w2
  int v68; // w1
  int v69; // w2
  int v70; // w1
  int v71; // w2
  int v72; // w1
  int v73; // w2
  int v74; // w1
  int v75; // w2
  int v76; // w1
  int v77; // w2
  int v78; // w1
  int v79; // w2
  int v80; // w1
  int v81; // w2
  int v82; // w1
  int v83; // w2
  int v84; // w1
  int v85; // w2
  int v86; // w1
  int v87; // w2
  int v88; // w1
  int v89; // w2
  int v90; // w1
  int v91; // w2
  int v92; // w1
  int v93; // w2
  int v94; // w1
  int v95; // w2
  int v96; // w1
  int v97; // w2
  int v98; // w1
  int v99; // w2
  int v100; // w1
  int v101; // w2
  int v102; // w1
  int v103; // w2
  int v104; // w1
  int v105; // w2
  int v106; // w1
  int v107; // w2
  int v108; // w1
  int v109; // w2
  int v110; // w1
  int v111; // w2

  printk(&unk_42B13E);
  if ( (zte_cam_cci_i2c_write(*a1 + 3656LL, 28690, 10, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  _const_udelay("d: %u rc: %d", v2, v3);
  if ( (zte_cam_cci_i2c_write(*a1 + 3656LL, 28688, 40960, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  _const_udelay("d: %u rc: %d", v4, v5);
  if ( (zte_cam_cci_i2c_write(*a1 + 3656LL, 28687, 22873, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  _const_udelay("d: %u rc: %d", v6, v7);
  if ( (zte_cam_cci_i2c_write(*a1 + 3656LL, 28689, 1, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  _const_udelay("d: %u rc: %d", v8, v9);
  _const_udelay("d: %u rc: %d", v10, v11);
  _const_udelay("d: %u rc: %d", v12, v13);
  _const_udelay("d: %u rc: %d", v14, v15);
  _const_udelay("d: %u rc: %d", v16, v17);
  _const_udelay("d: %u rc: %d", v18, v19);
  _const_udelay("d: %u rc: %d", v20, v21);
  _const_udelay("d: %u rc: %d", v22, v23);
  _const_udelay("d: %u rc: %d", v24, v25);
  _const_udelay("d: %u rc: %d", v26, v27);
  _const_udelay("d: %u rc: %d", v28, v29);
  _const_udelay("d: %u rc: %d", v30, v31);
  _const_udelay("d: %u rc: %d", v32, v33);
  _const_udelay("d: %u rc: %d", v34, v35);
  _const_udelay("d: %u rc: %d", v36, v37);
  _const_udelay("d: %u rc: %d", v38, v39);
  _const_udelay("d: %u rc: %d", v40, v41);
  _const_udelay("d: %u rc: %d", v42, v43);
  _const_udelay("d: %u rc: %d", v44, v45);
  _const_udelay("d: %u rc: %d", v46, v47);
  _const_udelay("d: %u rc: %d", v48, v49);
  _const_udelay("d: %u rc: %d", v50, v51);
  _const_udelay("d: %u rc: %d", v52, v53);
  _const_udelay("d: %u rc: %d", v54, v55);
  _const_udelay("d: %u rc: %d", v56, v57);
  _const_udelay("d: %u rc: %d", v58, v59);
  _const_udelay("d: %u rc: %d", v60, v61);
  _const_udelay("d: %u rc: %d", v62, v63);
  _const_udelay("d: %u rc: %d", v64, v65);
  _const_udelay("d: %u rc: %d", v66, v67);
  _const_udelay("d: %u rc: %d", v68, v69);
  _const_udelay("d: %u rc: %d", v70, v71);
  _const_udelay("d: %u rc: %d", v72, v73);
  _const_udelay("d: %u rc: %d", v74, v75);
  _const_udelay("d: %u rc: %d", v76, v77);
  _const_udelay("d: %u rc: %d", v78, v79);
  _const_udelay("d: %u rc: %d", v80, v81);
  _const_udelay("d: %u rc: %d", v82, v83);
  _const_udelay("d: %u rc: %d", v84, v85);
  _const_udelay("d: %u rc: %d", v86, v87);
  if ( !(unsigned int)dw9785_wait_check_register(a1, 0x701Eu, 0x8000) )
  {
    printk(&unk_432CB1);
    if ( (zte_cam_cci_i2c_write(*a1 + 3656LL, 56978, 56918, 2, 2) & 0x80000000) != 0 )
      printk(&unk_41BA38);
    _const_udelay("d: %u rc: %d", v88, v89);
    if ( (zte_cam_cci_i2c_write(*a1 + 3656LL, 53266, 2, 2, 2) & 0x80000000) != 0 )
      printk(&unk_41BA38);
    _const_udelay("d: %u rc: %d", v90, v91);
    _const_udelay("d: %u rc: %d", v92, v93);
    _const_udelay("d: %u rc: %d", v94, v95);
    _const_udelay("d: %u rc: %d", v96, v97);
    _const_udelay("d: %u rc: %d", v98, v99);
    _const_udelay("d: %u rc: %d", v100, v101);
    _const_udelay("d: %u rc: %d", v102, v103);
    _const_udelay("d: %u rc: %d", v104, v105);
    _const_udelay("d: %u rc: %d", v106, v107);
    _const_udelay("d: %u rc: %d", v108, v109);
    if ( (zte_cam_cci_i2c_write(*a1 + 3656LL, 28702, 32769, 2, 2) & 0x80000000) != 0 )
      printk(&unk_41BA38);
    _const_udelay("d: %u rc: %d", v110, v111);
  }
  if ( (unsigned int)dw9785_wait_check_register(a1, 0x7010u, 40961) )
  {
    printk(&unk_41BA72);
    return 0xFFFFFFFFLL;
  }
  else
  {
    ois_reset_ois_dw9785(a1);
    printk(&unk_432CF8);
    return 0;
  }
}
