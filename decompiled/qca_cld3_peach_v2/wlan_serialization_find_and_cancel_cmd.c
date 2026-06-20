__int64 __fastcall wlan_serialization_find_and_cancel_cmd(
        unsigned int *a1,
        int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_from_cmd; // x0
  __int64 v15; // x21
  __int64 pdev_obj; // x0
  __int64 v17; // x19
  char v18; // w22
  int v19; // w20
  const char *v20; // x2
  char v22; // w23
  __int64 v23; // x20
  _BOOL4 v24; // w21
  char v25; // w22
  int v26; // w19
  int v27; // w0
  _BOOL4 v28; // w9
  _BOOL4 v29; // w11
  bool v30; // zf
  char v31; // w23
  __int64 v32; // x19
  _BOOL4 v33; // w20
  __int64 v34; // x19
  char v35; // w23
  __int64 v36; // x20
  __int64 v37; // x19
  char v38; // w23
  __int64 v39; // x20
  char v40; // w22
  __int64 v41; // x21
  __int64 v42; // x2
  unsigned int *v43; // x3
  unsigned int v44; // w22
  __int64 v45; // x0
  __int64 v46; // x2
  unsigned int *v47; // x3
  __int64 v48; // x20
  bool v49; // zf
  __int64 v50; // x6
  unsigned int v51; // w8
  int v52; // w0
  unsigned int v53; // w22
  unsigned int v54; // w8
  int v55; // w0
  __int64 v56; // x21
  int v57; // w8
  unsigned int v58; // w9
  unsigned int v59; // w10
  int v60; // w0

  if ( !a1 )
  {
    v20 = "%s: Invalid cmd";
LABEL_13:
    qdf_trace_msg(0x4Cu, 2u, v20, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_serialization_find_and_cancel_cmd");
    return 4;
  }
  pdev_from_cmd = wlan_serialization_get_pdev_from_cmd(a1);
  if ( !pdev_from_cmd )
  {
    v20 = "%s: Invalid pdev";
    goto LABEL_13;
  }
  v15 = pdev_from_cmd;
  pdev_obj = wlan_serialization_get_pdev_obj(pdev_from_cmd);
  if ( !pdev_obj )
  {
    v20 = "%s: Invalid ser_obj";
    goto LABEL_13;
  }
  if ( a2 > 4 )
  {
    if ( a2 > 6 )
    {
      if ( a2 == 7 )
      {
        v37 = *((_QWORD *)a1 + 4);
        v38 = a3;
        if ( (a3 & 1) != 0 )
        {
          v39 = pdev_obj;
          v24 = wlan_ser_cancel_non_scan_cmd(pdev_obj, 0, v37, 0, 1, 1, 2) == 1;
        }
        else
        {
          v39 = pdev_obj;
          v24 = 0;
        }
        v44 = 1;
        if ( (v38 & 2) != 0 )
        {
          v45 = v39;
          v46 = v37;
          v47 = nullptr;
          v50 = 2;
LABEL_51:
          v52 = wlan_ser_cancel_non_scan_cmd(v45, 0, v46, v47, 1, 0, v50);
          v51 = 4 * (v52 != 0);
          if ( v24 && v52 == 0 )
            v44 = 2;
          else
            v44 = 1;
          goto LABEL_54;
        }
      }
      else
      {
        if ( a2 != 8 )
        {
LABEL_37:
          v20 = "%s: Invalid request";
          goto LABEL_13;
        }
        v22 = a3;
        if ( (a3 & 1) != 0 )
        {
          v23 = pdev_obj;
          v24 = wlan_ser_cancel_non_scan_cmd(pdev_obj, 0, 0, a1, 1, 1, 0) == 1;
        }
        else
        {
          v23 = pdev_obj;
          v24 = 0;
        }
        v44 = 1;
        if ( (v22 & 2) != 0 )
        {
          v45 = v23;
          v46 = 0;
          v47 = a1;
LABEL_46:
          v50 = 0;
          goto LABEL_51;
        }
      }
    }
    else
    {
      if ( a2 != 5 )
        return wlan_serialization_cmd_cancel_handler(
                 pdev_obj,
                 0,
                 0,
                 *((_QWORD *)a1 + 4),
                 *a1,
                 a3,
                 0,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11);
      v34 = *((_QWORD *)a1 + 4);
      v35 = a3;
      if ( (a3 & 1) != 0 )
      {
        v36 = pdev_obj;
        v24 = wlan_ser_cancel_non_scan_cmd(pdev_obj, 0, v34, 0, 1, 1, 0) == 1;
      }
      else
      {
        v36 = pdev_obj;
        v24 = 0;
      }
      v44 = 1;
      if ( (v35 & 2) != 0 )
      {
        v45 = v36;
        v46 = v34;
        v47 = nullptr;
        goto LABEL_46;
      }
    }
    v51 = 4;
LABEL_54:
    if ( v24 )
      return v44;
    else
      return v51;
  }
  if ( a2 <= 1 )
  {
    if ( !a2 )
    {
      v40 = a3;
      if ( (a3 & 1) != 0 )
      {
        v56 = pdev_obj;
        v19 = wlan_ser_cancel_scan_cmd(pdev_obj, 0, 0, a1, 0, 1);
        pdev_obj = v56;
        if ( (v40 & 2) == 0 )
          goto LABEL_67;
      }
      else
      {
        v19 = 4;
        if ( (v40 & 2) == 0 )
          goto LABEL_67;
      }
      v42 = 0;
      v43 = a1;
      goto LABEL_73;
    }
    if ( a2 == 1 )
    {
      v25 = a3;
      if ( (a3 & 1) != 0 )
      {
        v48 = pdev_obj;
        v26 = wlan_ser_cancel_scan_cmd(pdev_obj, v15, 0, 0, 0, 1);
        pdev_obj = v48;
        if ( (v25 & 2) != 0 )
          goto LABEL_25;
      }
      else
      {
        v26 = 4;
        if ( (a3 & 2) != 0 )
        {
LABEL_25:
          v27 = wlan_ser_cancel_scan_cmd(pdev_obj, v15, 0, 0, 0, 0);
          v28 = v27 != 0;
          v29 = v27 == 0;
          v30 = v26 == 1;
LABEL_74:
          v57 = v30;
          v58 = 4 * v28;
          if ( (v57 & v29) != 0 )
            v59 = 2;
          else
            v59 = 1;
          goto LABEL_80;
        }
      }
      v49 = v26 == 1;
LABEL_68:
      v57 = v49;
      v58 = 4;
      v59 = 1;
LABEL_80:
      if ( v57 )
        return v59;
      else
        return v58;
    }
    goto LABEL_37;
  }
  if ( (unsigned int)(a2 - 2) < 2 )
  {
    v17 = *((_QWORD *)a1 + 4);
    v18 = a3;
    if ( (a3 & 1) == 0 )
    {
      v19 = 4;
      if ( (v18 & 2) == 0 )
        goto LABEL_67;
      goto LABEL_36;
    }
    v41 = pdev_obj;
    v19 = wlan_ser_cancel_scan_cmd(pdev_obj, 0, v17, 0, 0, 1);
    pdev_obj = v41;
    if ( (v18 & 2) != 0 )
    {
LABEL_36:
      v42 = v17;
      v43 = nullptr;
LABEL_73:
      v60 = wlan_ser_cancel_scan_cmd(pdev_obj, 0, v42, v43, 0, 0);
      v28 = v60 != 0;
      v29 = v60 == 0;
      v30 = v19 == 1;
      goto LABEL_74;
    }
LABEL_67:
    v49 = v19 == 1;
    goto LABEL_68;
  }
  v31 = a3;
  v32 = pdev_obj;
  v33 = (a3 & 1) != 0 && wlan_ser_cancel_non_scan_cmd(pdev_obj, v15, 0, 0, 1, 1, 0) == 1;
  v53 = 1;
  if ( (v31 & 2) != 0 )
  {
    v55 = wlan_ser_cancel_non_scan_cmd(v32, v15, 0, 0, 1, 0, 0);
    v54 = 4 * (v55 != 0);
    if ( v33 && v55 == 0 )
      v53 = 2;
    else
      v53 = 1;
  }
  else
  {
    v54 = 4;
  }
  if ( v33 )
    return v53;
  else
    return v54;
}
