// positive sp value has been detected, the output may be wrong!
__int64 __fastcall cam_sensor_generic_blob_handler(
        size_t a1,
        int a2,
        unsigned int a3,
        char *string,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        __int64 a11,
        int a12,
        __int64 a13,
        int a14,
        __int64 a15,
        int a16,
        __int64 a17,
        int a18,
        __int64 a19,
        int a20,
        __int64 a21)
{
  __int64 v21; // x8
  __int64 v22; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v28; // x9
  unsigned int v29; // w20
  const char *v31; // x7
  size_t v32; // x22
  __int64 v34; // x9
  __int64 v35; // x8
  __int64 v36; // x9
  size_t v37; // x24
  size_t v38; // x20
  unsigned __int64 v39; // x2
  unsigned __int16 *v40; // x23
  const char *v41; // x20
  int v42; // w9
  __int64 v43; // x10
  int v44; // w10
  int v45; // w11
  const char *v46; // x3
  const char *v47; // x5
  __int64 v48; // x4
  const char *v49; // x6
  __int64 result; // x0
  __int64 (__fastcall *v51)(_QWORD); // x8
  __int64 v52; // x9
  unsigned int v53; // w10
  int v54; // w11
  __int64 v55; // x12
  __int64 v56; // x10
  size_t v57; // x19
  __int64 v58; // x6
  unsigned int v59; // w19
  int v60; // w7
  int v61; // w12
  size_t v62; // x20
  unsigned __int64 v63; // [xsp-30h] [xbp-B0h] BYREF
  __int64 v64; // [xsp-28h] [xbp-A8h]
  __int64 v65; // [xsp-20h] [xbp-A0h]
  __int64 v66; // [xsp-18h] [xbp-98h]
  __int64 v67; // [xsp-10h] [xbp-90h]
  __int64 v68; // [xsp-8h] [xbp-88h]
  __int64 v69; // [xsp+0h] [xbp-80h]
  __int64 v70; // [xsp+8h] [xbp-78h]

  v31 = (const char *)a3;
  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 || !string )
  {
    v46 = "cam_sensor_generic_blob_handler";
    v47 = "Invalid blob info %pK %u";
    v48 = 306;
    v49 = string;
LABEL_19:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, const char *))cam_print_log)(
      3,
      32,
      1,
      v46,
      v48,
      v47,
      v49,
      v31);
    result = 4294967274LL;
LABEL_41:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v32 = a1 + 4096;
  if ( a2 == 1 )
  {
    if ( a3 < 0x40 )
    {
      v46 = "cam_sensor_generic_blob_handler";
      v47 = "FRAME_INFO: Invalid blob size expected: 0x%x actual: 0x%x";
      v48 = 330;
      v49 = (const char *)&qword_40;
      goto LABEL_19;
    }
    v68 = 0;
    v69 = 0;
    v66 = 0;
    v67 = 0;
    v64 = 0;
    v65 = 0;
    v63 = 0;
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      v62 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_handle_frame_info",
        264,
        "sensor:%d req:%llu frame info: frame sync shift:%llu frame duration:%llu blanking duration:%llu",
        *(_DWORD *)(a1 + 52),
        *(_QWORD *)(a1 + 7600),
        *(_QWORD *)string,
        *((_QWORD *)string + 1),
        *((_QWORD *)string + 2));
      a1 = v62;
      v49 = *(const char **)(v62 + 7528);
      if ( v49 )
      {
LABEL_24:
        v51 = *((__int64 (__fastcall **)(_QWORD))v49 + 5);
        if ( v51 )
        {
          v52 = *(_QWORD *)(a1 + 7600);
          v53 = *(_DWORD *)(a1 + 7464);
          v54 = *(unsigned __int8 *)(v32 + 3526);
          v55 = *((_QWORD *)string + 2);
          LODWORD(v65) = 0;
          v64 = v52;
          LODWORD(v52) = *(_DWORD *)(a1 + 7456);
          v68 = v55;
          v63 = __PAIR64__(v52, v53);
          v56 = *((_QWORD *)string + 1);
          v66 = *(_QWORD *)string;
          v67 = v56;
          if ( v54 == 1 && *(_DWORD *)(a1 + 6544) == 2 )
            LOBYTE(v69) = 1;
          v57 = a1;
          if ( *((_DWORD *)v51 - 1) != 1498387893 )
            __break(0x8228u);
          result = v51(&v63);
          if ( (_DWORD)result )
          {
            v58 = *(_QWORD *)(v57 + 7600);
            v59 = result;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              32,
              1,
              "cam_sensor_handle_frame_info",
              290,
              "Failed to notify msg SENSOR_FRAME_INFO to CRM at req:%llu, rc:%d",
              v58,
              result);
            result = v59;
          }
          goto LABEL_41;
        }
      }
    }
    else
    {
      v49 = *(const char **)(a1 + 7528);
      if ( v49 )
        goto LABEL_24;
    }
    v46 = "cam_sensor_handle_frame_info";
    v47 = "Invalid crm_cb:%p or notify_msg:%p";
    v48 = 272;
    v31 = nullptr;
    goto LABEL_19;
  }
  if ( a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      2,
      "cam_sensor_generic_blob_handler",
      338,
      "Invalid blob type %d",
      a2);
LABEL_40:
    result = 0;
    goto LABEL_41;
  }
  if ( a3 < 0x5C )
  {
    v46 = "cam_sensor_generic_blob_handler";
    v47 = "RES_INFO: Invalid blob size expected: 0x%x actual: 0x%x";
    v48 = 317;
    v49 = (_BYTE *)(&qword_58 + 4);
    goto LABEL_19;
  }
  if ( !a1 )
  {
    v46 = "cam_sensor_handle_res_info";
    v47 = "Invalid params: res_info: %s, s_ctrl: %s";
    v49 = "Non-NULL";
    v31 = "NULL";
    v48 = 216;
    goto LABEL_19;
  }
  v35 = *(_QWORD *)(a1 + 7600);
  v34 = -v35;
  _NF = -v35 < 0;
  LODWORD(v35) = v35 & 0x1F;
  v36 = v34 & 0x1F;
  if ( !_NF )
    v35 = -v36;
  if ( (unsigned int)v35 >= 0x20uLL )
  {
    __break(0x5512u);
    goto LABEL_45;
  }
  v37 = a1;
  v38 = a1 + 88LL * (unsigned int)v35;
  *(_WORD *)(v38 + 3664) = *(_WORD *)string;
  a1 = strnlen(string + 14, 0x40u);
  if ( a1 >= 0x41 )
  {
LABEL_45:
    _fortify_panic(2, 64, a1 + 1);
    goto LABEL_46;
  }
  if ( a1 == 64 )
    v39 = 64;
  else
    v39 = a1 + 1;
  if ( v39 < 0x41 )
  {
    v40 = (unsigned __int16 *)(v38 + 3664);
    v41 = (const char *)(v38 + 3688);
    sized_strscpy(v41, string + 14);
    v42 = *(_DWORD *)(string + 6);
    *((_DWORD *)v40 + 2) = v42;
    *((_DWORD *)v40 + 3) = *(_DWORD *)(string + 10);
    *((_DWORD *)v40 + 1) = *(_DWORD *)(string + 2);
    v43 = *(_QWORD *)(v37 + 7600);
    v40[1] = 0;
    *((_QWORD *)v40 + 2) = v43;
    v44 = *(_DWORD *)(string + 78);
    if ( v44 )
    {
      v45 = *(_DWORD *)(string + 82);
      if ( (v45 & 1) != 0 )
      {
        v44 = *((unsigned __int16 *)string + 43);
        v40[1] = v44;
        v45 = *(_DWORD *)(string + 82);
      }
      else
      {
        v44 = 0;
      }
      if ( (v45 & 2) != 0 )
      {
        *(_DWORD *)(v37 + 7616) = *((unsigned __int16 *)string + 44);
        v44 = v40[1];
        v42 = *((_DWORD *)v40 + 2);
      }
    }
    v60 = *(_DWORD *)(v37 + 52);
    v61 = *v40;
    *(_BYTE *)(v32 + 3527) = 1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      3,
      "cam_sensor_handle_res_info",
      249,
      "Sensor[%s-%d] Feature: 0x%x updated for request id: %lu, res index: %u, width: %d, height: %d, capability: %s, fps: %u",
      (const char *)(v37 + 7560),
      v60,
      v44,
      *((_QWORD *)v40 + 2),
      v61,
      v42,
      *((_DWORD *)v40 + 3),
      v41,
      *((_DWORD *)v40 + 1));
    goto LABEL_40;
  }
LABEL_46:
  _fortify_panic(7, 64, v39);
  v22 = _arch_copy_to_user(v21 & 0xFF7FFFFFFFFFFFFFLL);
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v28 - 4096);
  _WriteStatusReg(TTBR1_EL1, v28);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
  if ( v22 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_driver_cmd",
      1677,
      "Failed Copy to User");
    v29 = -14;
  }
  else
  {
    v29 = 0;
  }
  mutex_lock(string + 7928);
  cam_sensor_util_release_read_buf(string + 7912);
  mutex_unlock(string + 7928);
  mutex_unlock(string + 3608);
  _ReadStatusReg(SP_EL0);
  return v29;
}
