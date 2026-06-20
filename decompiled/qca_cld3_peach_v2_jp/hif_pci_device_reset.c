__int64 __fastcall hif_pci_device_reset(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x21
  __int64 v11; // x19
  int v12; // w20
  int v13; // w0
  unsigned int *v14; // x8
  int v15; // w20
  int v16; // w0
  _DWORD *v17; // x8
  int v18; // w0
  int v19; // w0
  int v20; // w0
  int v21; // w0
  int v22; // w0
  int v23; // w0
  int v24; // w0
  int v25; // w0
  int v26; // w0
  int v27; // w0
  _DWORD *v28; // x8
  int v29; // w0
  int v30; // w0
  int v31; // w0
  int v32; // w0
  int v33; // w0
  int v34; // w0
  int v35; // w0
  int v36; // w0
  int v37; // w0

  v9 = *(_QWORD *)(result + 632);
  if ( v9 )
  {
    if ( *(_DWORD *)(v9 + 148) )
    {
      v10 = *(_QWORD *)(result + 30720);
      v11 = result;
      if ( v10 )
      {
        qdf_trace_msg(0x3Du, 2u, "%s: Reset Device", a2, a3, a4, a5, a6, a7, a8, a9, "hif_pci_device_reset");
        hif_write32_mb_reg_window(
          v11,
          v10 + *(_DWORD *)(*(_QWORD *)(v11 + 632) + 160LL) + *(_DWORD *)(*(_QWORD *)(v11 + 632) + 168LL),
          *(_DWORD *)(*(_QWORD *)(v11 + 632) + 172LL));
        v12 = 10;
        while ( 1 )
        {
          if ( (*(_BYTE *)(v11 + 648) & 1) == 0 )
          {
            v13 = hif_read32_mb_reg_window(
                    v11,
                    v10
                  + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                  + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
            v14 = *(unsigned int **)(v11 + 632);
            if ( (v14[49] & ~((v14[44] & v13) >> v14[45])) == 0 )
              break;
          }
          _const_udelay(4295000);
          if ( !--v12 )
          {
            v14 = *(unsigned int **)(v11 + 632);
            break;
          }
        }
        v15 = hif_read32_mb_reg_window(v11, v10 + v14[40] + v14[37]);
        hif_write32_mb_reg_window(
          v11,
          v10 + *(_DWORD *)(*(_QWORD *)(v11 + 632) + 160LL) + *(_DWORD *)(*(_QWORD *)(v11 + 632) + 148LL),
          v15 | 1);
        v16 = hif_read32_mb_reg_window(
                v11,
                v10
              + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
              + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
        v17 = *(_DWORD **)(v11 + 632);
        if ( (v17[39] & v16) == 0 )
        {
          _const_udelay(4295000);
          v18 = hif_read32_mb_reg_window(
                  v11,
                  v10
                + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
          v17 = *(_DWORD **)(v11 + 632);
          if ( (v17[39] & v18) == 0 )
          {
            _const_udelay(4295000);
            v19 = hif_read32_mb_reg_window(
                    v11,
                    v10
                  + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                  + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
            v17 = *(_DWORD **)(v11 + 632);
            if ( (v17[39] & v19) == 0 )
            {
              _const_udelay(4295000);
              v20 = hif_read32_mb_reg_window(
                      v11,
                      v10
                    + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                    + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
              v17 = *(_DWORD **)(v11 + 632);
              if ( (v17[39] & v20) == 0 )
              {
                _const_udelay(4295000);
                v21 = hif_read32_mb_reg_window(
                        v11,
                        v10
                      + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                      + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                v17 = *(_DWORD **)(v11 + 632);
                if ( (v17[39] & v21) == 0 )
                {
                  _const_udelay(4295000);
                  v22 = hif_read32_mb_reg_window(
                          v11,
                          v10
                        + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                        + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                  v17 = *(_DWORD **)(v11 + 632);
                  if ( (v17[39] & v22) == 0 )
                  {
                    _const_udelay(4295000);
                    v23 = hif_read32_mb_reg_window(
                            v11,
                            v10
                          + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                          + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                    v17 = *(_DWORD **)(v11 + 632);
                    if ( (v17[39] & v23) == 0 )
                    {
                      _const_udelay(4295000);
                      v24 = hif_read32_mb_reg_window(
                              v11,
                              v10
                            + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                            + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                      v17 = *(_DWORD **)(v11 + 632);
                      if ( (v17[39] & v24) == 0 )
                      {
                        _const_udelay(4295000);
                        v25 = hif_read32_mb_reg_window(
                                v11,
                                v10
                              + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                              + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                        v17 = *(_DWORD **)(v11 + 632);
                        if ( (v17[39] & v25) == 0 )
                        {
                          _const_udelay(4295000);
                          v26 = hif_read32_mb_reg_window(
                                  v11,
                                  v10
                                + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                                + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                          v17 = *(_DWORD **)(v11 + 632);
                          if ( (v17[39] & v26) == 0 )
                          {
                            _const_udelay(4295000);
                            v17 = *(_DWORD **)(v11 + 632);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        hif_write32_mb_reg_window(v11, v10 + v17[40] + v17[37], v15 & 0xFFFFFFFE);
        v27 = hif_read32_mb_reg_window(
                v11,
                v10
              + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
              + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
        v28 = *(_DWORD **)(v11 + 632);
        if ( (v28[39] & v27) != 0 )
        {
          _const_udelay(4295000);
          v29 = hif_read32_mb_reg_window(
                  v11,
                  v10
                + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
          v28 = *(_DWORD **)(v11 + 632);
          if ( (v28[39] & v29) != 0 )
          {
            _const_udelay(4295000);
            v30 = hif_read32_mb_reg_window(
                    v11,
                    v10
                  + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                  + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
            v28 = *(_DWORD **)(v11 + 632);
            if ( (v28[39] & v30) != 0 )
            {
              _const_udelay(4295000);
              v31 = hif_read32_mb_reg_window(
                      v11,
                      v10
                    + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                    + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
              v28 = *(_DWORD **)(v11 + 632);
              if ( (v28[39] & v31) != 0 )
              {
                _const_udelay(4295000);
                v32 = hif_read32_mb_reg_window(
                        v11,
                        v10
                      + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                      + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                v28 = *(_DWORD **)(v11 + 632);
                if ( (v28[39] & v32) != 0 )
                {
                  _const_udelay(4295000);
                  v33 = hif_read32_mb_reg_window(
                          v11,
                          v10
                        + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                        + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                  v28 = *(_DWORD **)(v11 + 632);
                  if ( (v28[39] & v33) != 0 )
                  {
                    _const_udelay(4295000);
                    v34 = hif_read32_mb_reg_window(
                            v11,
                            v10
                          + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                          + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                    v28 = *(_DWORD **)(v11 + 632);
                    if ( (v28[39] & v34) != 0 )
                    {
                      _const_udelay(4295000);
                      v35 = hif_read32_mb_reg_window(
                              v11,
                              v10
                            + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                            + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                      v28 = *(_DWORD **)(v11 + 632);
                      if ( (v28[39] & v35) != 0 )
                      {
                        _const_udelay(4295000);
                        v36 = hif_read32_mb_reg_window(
                                v11,
                                v10
                              + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                              + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                        v28 = *(_DWORD **)(v11 + 632);
                        if ( (v28[39] & v36) != 0 )
                        {
                          _const_udelay(4295000);
                          v37 = hif_read32_mb_reg_window(
                                  v11,
                                  v10
                                + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 160LL)
                                + *(unsigned int *)(*(_QWORD *)(v11 + 632) + 152LL));
                          v28 = *(_DWORD **)(v11 + 632);
                          if ( (v28[39] & v37) != 0 )
                          {
                            _const_udelay(4295000);
                            v28 = *(_DWORD **)(v11 + 632);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        return hif_write32_mb_reg_window(v11, (int)v10 + v28[40] + v28[42], v28[41]);
      }
    }
  }
  return result;
}
