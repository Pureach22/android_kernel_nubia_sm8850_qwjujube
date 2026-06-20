__int64 __fastcall hal_write32_mb_confirm_retry(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7

  result = ((__int64 (*)(void))hal_write32_mb_confirm)();
  if ( (_DWORD)result )
  {
    result = hal_read32_mb_0(a1, a2);
    if ( (_DWORD)result != a3 )
    {
      qdf_trace_msg(
        0x46u,
        3u,
        "%s: Retry reg offset 0x%x, value 0x%x, read value 0x%x",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "hal_write32_mb_confirm_retry",
        a2,
        a3,
        (unsigned int)result);
      _const_udelay(4295000);
      result = hal_write32_mb_confirm(a1, a2, a3);
      if ( (_DWORD)result )
      {
        result = hal_read32_mb_0(a1, a2);
        if ( (_DWORD)result != a3 )
        {
          qdf_trace_msg(
            0x46u,
            3u,
            "%s: Retry reg offset 0x%x, value 0x%x, read value 0x%x",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "hal_write32_mb_confirm_retry",
            a2,
            a3,
            (unsigned int)result);
          _const_udelay(4295000);
          result = hal_write32_mb_confirm(a1, a2, a3);
          if ( (_DWORD)result )
          {
            result = hal_read32_mb_0(a1, a2);
            if ( (_DWORD)result != a3 )
            {
              qdf_trace_msg(
                0x46u,
                3u,
                "%s: Retry reg offset 0x%x, value 0x%x, read value 0x%x",
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                "hal_write32_mb_confirm_retry",
                a2,
                a3,
                (unsigned int)result);
              _const_udelay(4295000);
              result = hal_write32_mb_confirm(a1, a2, a3);
              if ( (_DWORD)result )
              {
                result = hal_read32_mb_0(a1, a2);
                if ( (_DWORD)result != a3 )
                {
                  qdf_trace_msg(
                    0x46u,
                    3u,
                    "%s: Retry reg offset 0x%x, value 0x%x, read value 0x%x",
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    "hal_write32_mb_confirm_retry",
                    a2,
                    a3,
                    (unsigned int)result);
                  _const_udelay(4295000);
                  result = hal_write32_mb_confirm(a1, a2, a3);
                  if ( (_DWORD)result )
                  {
                    result = hal_read32_mb_0(a1, a2);
                    if ( (_DWORD)result != a3 )
                    {
                      qdf_trace_msg(
                        0x46u,
                        3u,
                        "%s: Retry reg offset 0x%x, value 0x%x, read value 0x%x",
                        v39,
                        v40,
                        v41,
                        v42,
                        v43,
                        v44,
                        v45,
                        v46,
                        "hal_write32_mb_confirm_retry",
                        a2,
                        a3,
                        (unsigned int)result);
                      _const_udelay(4295000);
                      result = hal_write32_mb_confirm(a1, a2, a3);
                      if ( (_DWORD)result )
                      {
                        result = hal_read32_mb_0(a1, a2);
                        if ( (_DWORD)result != a3 )
                        {
                          qdf_trace_msg(
                            0x46u,
                            3u,
                            "%s: Retry reg offset 0x%x, value 0x%x, read value 0x%x",
                            v47,
                            v48,
                            v49,
                            v50,
                            v51,
                            v52,
                            v53,
                            v54,
                            "hal_write32_mb_confirm_retry",
                            a2,
                            a3,
                            (unsigned int)result);
                          _const_udelay(4295000);
                          return _qdf_trigger_self_recovery();
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
    }
  }
  return result;
}
