__int64 __fastcall qcom_mdt_pas_init(
        __int64 a1,
        _QWORD *a2,
        char *a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        char a7)
{
  __int64 v12; // x10
  __int64 v13; // x9
  int v14; // w28
  unsigned __int64 v15; // x27
  _DWORD *v16; // x10
  unsigned __int64 v17; // x24
  int v18; // w12
  unsigned __int64 v19; // x14
  unsigned __int64 v20; // x12
  unsigned __int64 metadata; // x26
  __int64 v22; // x25
  unsigned int inited; // w0
  __int64 result; // x0
  int v25; // w2
  __int64 v26; // x0
  unsigned int v27; // w21
  char *v28; // x8
  unsigned int v29; // [xsp+4h] [xbp-1Ch]
  _QWORD v31[2]; // [xsp+10h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a2[1];
  v13 = *(unsigned __int16 *)(v12 + 44);
  if ( *(_WORD *)(v12 + 44) )
  {
    v14 = 0;
    v15 = 0;
    v16 = (_DWORD *)(v12 + 76);
    v17 = -1;
    do
    {
      if ( *(v16 - 6) == 1 && (*v16 & 0x7000000) != 0x2000000 )
      {
        v18 = *(v16 - 1);
        if ( v18 )
        {
          v19 = (unsigned int)*(v16 - 3);
          v14 |= (*v16 & 0x8000000u) >> 27;
          v20 = (unsigned int)(v18 + v19);
          if ( v17 >= v19 )
            v17 = (unsigned int)*(v16 - 3);
          if ( v15 < v20 )
            v15 = ((_DWORD)v20 + 4095) & 0xFFFFF000;
        }
      }
      --v13;
      v16 += 8;
    }
    while ( v13 );
  }
  else
  {
    v15 = 0;
    LOBYTE(v14) = 0;
    v17 = -1;
  }
  v31[0] = 0;
  metadata = qcom_mdt_read_metadata(a2, v31, a3, a1);
  if ( metadata >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a1, "error %d reading firmware %s metadata\n", metadata, a3);
    result = (unsigned int)metadata;
    goto LABEL_24;
  }
  if ( (a7 & 1) != 0 )
    v22 = a1;
  else
    v22 = 0;
  inited = qcom_scm_pas_init_image(a4, metadata, v31[0], a6, v22);
  if ( !inited )
  {
    kfree(metadata);
    goto LABEL_18;
  }
  v29 = inited;
  if ( strstr(a3, "adsp") )
  {
    dev_err(a1, "error %d initializing firmware %s, try again\n", v29, a3);
    v29 = qcom_scm_pas_init_image(a4, metadata, v31[0], a6, v22);
    kfree(metadata);
    if ( !v29 )
    {
LABEL_18:
      if ( (v14 & 1) != 0 )
      {
        result = qcom_scm_pas_mem_setup(a4, a5, v15 - v17);
        if ( (_DWORD)result )
        {
          v25 = result;
          v26 = a1;
          v27 = v25;
          dev_err(v26, "error %d setting up firmware %s\n", v25, a3);
          if ( (a7 & 1) != 0 )
            qcom_scm_pas_shutdown(a4);
          qcom_scm_pas_metadata_release(a6, v22);
          result = v27;
        }
      }
      else
      {
        result = 0;
      }
      goto LABEL_24;
    }
  }
  else
  {
    kfree(metadata);
  }
  dev_err(a1, "error %d initializing firmware %s\n", v29, a3);
  v28 = strstr(a3, "adsp");
  result = v29;
  if ( v28 )
    panic("initializing firmware %s failed\n", a3);
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
