__int64 __fastcall sg_write(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v4; // x19
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 result; // x0
  __int64 v8; // x20
  __int64 v9; // x8
  __int64 v10; // x21
  unsigned __int64 v11; // x22
  __int64 v12; // x23
  int v13; // w0
  int v14; // w8
  __int64 v15; // x23
  unsigned __int64 v16; // x21
  __int64 v17; // x22
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  __int64 v25; // x23
  unsigned __int64 v26; // x8
  __int64 v28; // x0
  __int64 v34; // x0
  __int64 v35; // x22
  unsigned int v36; // w26
  unsigned int v37; // w8
  int v38; // w10
  int v39; // w9
  int v40; // w24
  int v41; // w9
  int v42; // w10
  __int64 v43; // x10
  int v44; // w11
  int v45; // w9
  __int64 v46; // [xsp+0h] [xbp-130h] BYREF
  __int64 v47; // [xsp+8h] [xbp-128h]
  __int64 v48; // [xsp+10h] [xbp-120h]
  __int64 v49; // [xsp+18h] [xbp-118h]
  __int64 v50; // [xsp+20h] [xbp-110h]
  __int64 v51; // [xsp+28h] [xbp-108h]
  __int64 v52; // [xsp+30h] [xbp-100h]
  __int64 v53; // [xsp+38h] [xbp-F8h]
  __int64 v54; // [xsp+40h] [xbp-F0h]
  __int64 v55; // [xsp+48h] [xbp-E8h]
  __int64 v56; // [xsp+50h] [xbp-E0h]
  __int64 v57; // [xsp+58h] [xbp-D8h]
  __int64 v58; // [xsp+60h] [xbp-D0h]
  __int64 v59; // [xsp+68h] [xbp-C8h]
  __int64 v60; // [xsp+70h] [xbp-C0h]
  __int64 v61; // [xsp+78h] [xbp-B8h]
  __int64 v62; // [xsp+80h] [xbp-B0h]
  __int64 v63; // [xsp+88h] [xbp-A8h]
  __int64 v64; // [xsp+90h] [xbp-A0h]
  __int64 v65; // [xsp+98h] [xbp-98h]
  __int64 v66; // [xsp+A0h] [xbp-90h]
  __int64 v67; // [xsp+A8h] [xbp-88h]
  __int64 v68; // [xsp+B0h] [xbp-80h]
  __int64 v69; // [xsp+B8h] [xbp-78h]
  __int64 v70; // [xsp+C0h] [xbp-70h]
  __int64 v71; // [xsp+C8h] [xbp-68h]
  __int64 v72; // [xsp+D0h] [xbp-60h]
  __int64 v73; // [xsp+D8h] [xbp-58h]
  __int64 v74; // [xsp+E0h] [xbp-50h]
  __int64 v75; // [xsp+E8h] [xbp-48h]
  __int64 v76; // [xsp+F0h] [xbp-40h]
  int v77; // [xsp+F8h] [xbp-38h]
  __int64 v78; // [xsp+100h] [xbp-30h] BYREF
  __int64 v79; // [xsp+108h] [xbp-28h]
  __int64 v80; // [xsp+110h] [xbp-20h]
  __int64 v81; // [xsp+118h] [xbp-18h]
  int v82; // [xsp+120h] [xbp-10h]
  __int64 v83; // [xsp+128h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = _ReadStatusReg(SP_EL0);
  v83 = *(_QWORD *)(StatusReg + 1808);
  v5 = *(_QWORD *)(a1 + 56);
  v6 = *(_QWORD *)(v4 + 2296);
  v82 = 0;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  v77 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v46 = 0;
  if ( v5 != v6 )
  {
    if ( (sg_check_file_access___already_done & 1) == 0 )
    {
      sg_check_file_access___already_done = 1;
      _task_pid_nr_ns(v4, 1, 0);
      printk(&unk_B5E7, "sg_write");
    }
    result = -1;
    goto LABEL_14;
  }
  v8 = *(_QWORD *)(a1 + 32);
  if ( !v8 )
    goto LABEL_13;
  v9 = *(_QWORD *)(v8 + 16);
  if ( !v9 )
    goto LABEL_13;
  if ( *(_DWORD *)(v9 + 112) )
  {
    result = -19;
    goto LABEL_14;
  }
  if ( (*(_BYTE *)(a1 + 49) & 8) == 0 )
  {
    v10 = a1;
    v11 = a3;
    v12 = a2;
    v13 = scsi_block_when_processing_errors(*(_QWORD *)v9);
    a2 = v12;
    a3 = v11;
    v14 = v13;
    a1 = v10;
    if ( !v14 )
    {
LABEL_13:
      result = -6;
      goto LABEL_14;
    }
  }
  if ( a3 < 0x24 )
  {
LABEL_12:
    result = -5;
    goto LABEL_14;
  }
  v15 = a1;
  v16 = a3;
  v17 = a2;
  if ( inline_copy_from_user((int)&v78, a2, 0x24u) )
    goto LABEL_16;
  if ( v78 < 0 )
  {
    result = sg_new_write(
               v8,
               v15,
               v17,
               v16,
               0,
               0,
               0,
               v24,
               v46,
               v47,
               v48,
               v49,
               v50,
               v51,
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               v59,
               v60,
               v61,
               v62,
               v63,
               v64,
               v65,
               v66,
               v67,
               v68,
               v69,
               v70,
               v71,
               v72,
               v73,
               v74,
               v75,
               v76,
               v77,
               v78);
    goto LABEL_14;
  }
  if ( v16 < 0x2A )
    goto LABEL_12;
  v25 = v17 + 36;
  if ( (*(_BYTE *)(v4 + 70) & 0x20) != 0 || (v26 = v17 + 36, (*(_QWORD *)v4 & 0x4000000) != 0) )
    v26 = v25 & (v25 << 8 >> 8);
  if ( v26 >> 39 )
  {
LABEL_16:
    result = -14;
    goto LABEL_14;
  }
  _X22 = v25 & 0xFF7FFFFFFFFFFFFFLL;
  v28 = uaccess_ttbr0_enable(
          0,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70);
  __asm { LDTRB           W24, [X22] }
  uaccess_ttbr0_disable(v28);
  v34 = sg_add_request(v8);
  if ( !v34 )
  {
    result = -33;
    goto LABEL_14;
  }
  v35 = v34;
  mutex_lock(v8 + 56);
  v36 = *(unsigned __int8 *)(v8 + 4906);
  if ( *(_BYTE *)(v8 + 4906) )
  {
    *(_BYTE *)(v8 + 4906) = 0;
  }
  else
  {
    v36 = *((unsigned __int8 *)&scsi_command_size_tbl + ((unsigned __int8)_X24 >> 5));
    if ( (~(_BYTE)_X24 & 0xC0) == 0 && (v80 & 1) != 0 )
      v36 = 12;
  }
  mutex_unlock(v8 + 56);
  v37 = HIDWORD(v78);
  v38 = v16 - v36;
  if ( SHIDWORD(v78) <= (int)(v16 - v36) )
    v39 = v16 - v36;
  else
    v39 = HIDWORD(v78);
  v40 = v38 - 36;
  if ( v38 - 36 < 0 )
  {
    sg_remove_request(v8, v35);
    result = -5;
    goto LABEL_14;
  }
  v41 = v39 - 36;
  *(_DWORD *)(v35 + 56) = 0;
  *(_BYTE *)(v35 + 64) = v36;
  *(_WORD *)(v35 + 66) = 0;
  *(_BYTE *)(v35 + 65) = 0;
  if ( v38 == 36 )
  {
    v43 = 0;
    if ( v41 <= 0 )
      v44 = -1;
    else
      v44 = -3;
    *(_DWORD *)(v35 + 68) = v41;
    *(_DWORD *)(v35 + 60) = v44;
  }
  else
  {
    if ( v37 <= 0x24 )
      v42 = -2;
    else
      v42 = -4;
    *(_DWORD *)(v35 + 68) = v41;
    *(_DWORD *)(v35 + 60) = v42;
    v43 = v25 + v36;
  }
  v45 = v79;
  *(_QWORD *)(v35 + 72) = v43;
  *(_QWORD *)(v35 + 88) = 0;
  *(_DWORD *)(v35 + 96) = v37;
  *(_DWORD *)(v35 + 100) = v40;
  *(_DWORD *)(v35 + 104) = v45;
  *(_QWORD *)(v35 + 112) = 0;
  if ( v36 >= 0xFD )
  {
    _copy_overflow(252, v36);
    goto LABEL_47;
  }
  _check_object_size(&v46, v36, 0);
  if ( inline_copy_from_user((int)&v46, v25, v36) )
  {
LABEL_47:
    sg_remove_request(v8, v35);
    result = -14;
    goto LABEL_14;
  }
  if ( *(_DWORD *)(v35 + 60) == -4 && (unsigned int)__ratelimit(&sg_write__rs, "sg_write") )
    printk(&unk_B655, (unsigned int)(HIDWORD(v78) - 36));
  LODWORD(result) = sg_common_write(v8, v35, &v46, *(unsigned int *)(v8 + 104));
  if ( (int)result >= 0 )
    result = v16;
  else
    result = (int)result;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
