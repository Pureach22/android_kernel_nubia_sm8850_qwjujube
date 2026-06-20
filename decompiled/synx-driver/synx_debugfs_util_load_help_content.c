__int64 __fastcall synx_debugfs_util_load_help_content(_QWORD *a1, _QWORD *a2)
{
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x1
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x1
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x1
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 result; // x0

  v4 = *a1 + (int)scnprintf(*a1, *a2 - *a1, "\n\n\tSynx tables Supported for debugfs with the column names:");
  *a1 = v4;
  v5 = *a1 + (int)scnprintf(v4, *a2 - v4, "\n\n\tGLOBAL/LOCAL MAP COLUMNS : STATUS, ID, REF_CNT, BOUND,");
  *a1 = v5;
  v6 = *a2 - v5;
  if ( (unsigned __int64)(8 * v6 - 28) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v5 = *a1 + (int)scnprintf(v5, v6, "\tGLOBAL INDEX, MAP CNT\n");
    *a1 = v5;
    v6 = *a2 - v5;
  }
  if ( (v6 & 0x1FFFFFFFFFFFFFFFLL) != 6 )
  {
    v5 = *a1 + (int)scnprintf(v5, v6, "\n\tGLOBAL SHARED MEMORY COLUMNS : STATUS, ID,");
    *a1 = v5;
    v6 = *a2 - v5;
  }
  v7 = *a1 + (int)scnprintf(v5, v6, "REF_CNT, NUM_CHILD, \tSUBSCRIBERS, WAITERS, PARENTS");
  *a1 = v7;
  v8 = *a2 - v7;
  if ( (unsigned __int64)(8 * v8 - 60) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v7 = *a1 + (int)scnprintf(v7, v8, "\n\n\tCLIENT MAP COLUMNS : CLIENT_ID, REF_CNT, REL_CNT, ID");
    *a1 = v7;
    v8 = *a2 - v7;
  }
  if ( (v8 & 0x1FFFFFFFFFFFFFFFLL) != 7 )
  {
    v7 = *a1 + (int)scnprintf(v7, v8, "\n\n\tDMA FENCE COLUMNS: STATUS, ID, REF_CNT, DMA FENCE");
    *a1 = v7;
    v8 = *a2 - v7;
  }
  if ( (unsigned __int64)(8 * v8 - 36) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v7 = *a1 + (int)scnprintf(v7, v8, "\n\n\tINSTRUCTIONS TO BE FOLLOWED:");
    *a1 = v7;
    v8 = *a2 - v7;
  }
  v9 = *a1 + (int)scnprintf(v7, v8, "\n\n\tTO PRINT CHOOSE THE COLUMNS ACCORDINGLY AND ADD UP THE");
  *a1 = v9;
  v10 = *a2 - v9;
  if ( (unsigned __int64)(8 * v10 - 68) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v9 = *a1 + (int)scnprintf(v9, v10, "\tHEXADECIMAL VALUES & PASS THE ADDED UP VALUES FOR COLUMN ALONG");
    *a1 = v9;
    v10 = *a2 - v9;
  }
  v11 = *a1 + (int)scnprintf(v9, v10, "WITH TABLE SELECTION VALUE AS SHOWN BELOW:");
  *a1 = v11;
  v12 = *a2 - v11;
  if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 5 )
  {
    v11 = *a1 + (int)scnprintf(v11, v12, "\n\tSet Below Values for Column selection\n");
    *a1 = v11;
    v12 = *a2 - v11;
  }
  if ( (unsigned __int64)(8 * v12 - 34) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v11 = *a1 + (int)scnprintf(v11, v12, "\n\n\tNAME_COLUMN       = 0x0001");
    *a1 = v11;
    v12 = *a2 - v11;
  }
  if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
  {
    v11 = *a1 + (int)scnprintf(v11, v12, "\n\tID_COLUMN         = 0x0002");
    *a1 = v11;
    v12 = *a2 - v11;
    if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
    {
      v11 = *a1 + (int)scnprintf(v11, v12, "\n\tBOUND_COLUMN      = 0x0004");
      *a1 = v11;
      v12 = *a2 - v11;
      if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
      {
        v11 = *a1 + (int)scnprintf(v11, v12, "\n\tSTATUS_COLUMN     = 0x0008");
        *a1 = v11;
        v12 = *a2 - v11;
        if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
        {
          v11 = *a1 + (int)scnprintf(v11, v12, "\n\tFENCE_COLUMN      = 0x0010");
          *a1 = v11;
          v12 = *a2 - v11;
          if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
          {
            v11 = *a1 + (int)scnprintf(v11, v12, "\n\tCOREDATA_COLUMN   = 0x0020");
            *a1 = v11;
            v12 = *a2 - v11;
            if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
            {
              v11 = *a1 + (int)scnprintf(v11, v12, "\n\tGLOBAL_IDX_COLUMN = 0x0040");
              *a1 = v11;
              v12 = *a2 - v11;
              if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
              {
                v11 = *a1 + (int)scnprintf(v11, v12, "\n\tREL_CNT_COLUMN    = 0x0080");
                *a1 = v11;
                v12 = *a2 - v11;
                if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
                {
                  v11 = *a1 + (int)scnprintf(v11, v12, "\n\tMAP_CNT_COLUMN    = 0x0100");
                  *a1 = v11;
                  v12 = *a2 - v11;
                  if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
                  {
                    v11 = *a1 + (int)scnprintf(v11, v12, "\n\tREF_CNT_COLUMN    = 0x0200");
                    *a1 = v11;
                    v12 = *a2 - v11;
                    if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
                    {
                      v11 = *a1 + (int)scnprintf(v11, v12, "\n\tNUM_CHILD_COLUMN  = 0x0400");
                      *a1 = v11;
                      v12 = *a2 - v11;
                      if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
                      {
                        v11 = *a1 + (int)scnprintf(v11, v12, "\n\tSUBSCRIBERS_COLUMN= 0x0800");
                        *a1 = v11;
                        v12 = *a2 - v11;
                        if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
                        {
                          v11 = *a1 + (int)scnprintf(v11, v12, "\n\tWAITERS_COLUMN    = 0x1000");
                          *a1 = v11;
                          v12 = *a2 - v11;
                          if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
                          {
                            v11 = *a1 + (int)scnprintf(v11, v12, "\n\tPARENTS_COLUMN    = 0x2000");
                            *a1 = v11;
                            v12 = *a2 - v11;
                            if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
                            {
                              v11 = *a1 + (int)scnprintf(v11, v12, "\n\tCLIENT_ID_COLUMN  = 0x4000");
                              *a1 = v11;
                              v12 = *a2 - v11;
                              if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) == 5 )
                                goto LABEL_72;
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
    }
  }
  v11 = *a1 + (int)scnprintf(v11, v12, "\n\n\tSet Below Values for Table selection\n");
  *a1 = v11;
  v12 = *a2 - v11;
  if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
  {
LABEL_72:
    v11 = *a1 + (int)scnprintf(v11, v12, "\n\tLOCAL_HASHTABLE   = 0x00010000");
    *a1 = v11;
    v12 = *a2 - v11;
    if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
    {
      v11 = *a1 + (int)scnprintf(v11, v12, "\n\tGLOBAL_HASHTABLE  = 0x00020000");
      *a1 = v11;
      v12 = *a2 - v11;
      if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
      {
        v11 = *a1 + (int)scnprintf(v11, v12, "\n\tCLIENT_HASHTABLE  = 0x00040000");
        *a1 = v11;
        v12 = *a2 - v11;
        if ( (v12 & 0x1FFFFFFFFFFFFFFFLL) != 4 )
        {
          v11 = *a1 + (int)scnprintf(v11, v12, "\n\tGLOBAL_SHARED_MEM = 0x00080000");
          *a1 = v11;
          v12 = *a2 - v11;
        }
      }
    }
  }
  v13 = *a1 + (int)scnprintf(v11, v12, "\n\tDMA_FENCE_MAP     = 0x00100000\n");
  *a1 = v13;
  v14 = *a2 - v13;
  if ( (v14 & 0x1FFFFFFFFFFFFFFFLL) == 7
    || (v13 = *a1 + (int)scnprintf(v13, v14, "\n\tExample : To select Global map & all its columns :"),
        *a1 = v13,
        v14 = *a2 - v13,
        (v14 & 0x1FFFFFFFFFFFFFFFLL) != 4) )
  {
    v13 = *a1 + (int)scnprintf(v13, v14, "\n\t echo 0x2034E>column_level");
    *a1 = v13;
    v14 = *a2 - v13;
  }
  if ( (unsigned __int64)(8 * v14 - 44) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v13 = *a1 + (int)scnprintf(v13, v14, "\n\t Last four digits in hexadecimal flag");
    *a1 = v13;
    v14 = *a2 - v13;
  }
  v15 = *a1 + (int)scnprintf(v13, v14, " is dedicated for setting columns,");
  *a1 = v15;
  v16 = *a2 - v15;
  if ( (v16 & 0x1FFFFFFFFFFFFFFFLL) != 6 )
  {
    v15 = *a1 + (int)scnprintf(v15, v16, "\tuser can even set \"FFFF\" to set all columns");
    *a1 = v15;
    v16 = *a2 - v15;
  }
  v17 = *a1 + (int)scnprintf(v15, v16, "\n\t Instead of passing 0x2034E, \tuser can even pass");
  *a1 = v17;
  v18 = *a1 + (int)scnprintf(v17, *a2 - v17, " 0x2FFFF to fetch the same");
  *a1 = v18;
  v19 = *a2 - v18;
  if ( (unsigned __int64)(8 * v19 - 67) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v18 = *a1 + (int)scnprintf(v18, v19, "\n\n\tUser can set Handle Range with echo command as shown below\n");
    *a1 = v18;
    v19 = *a2 - v18;
  }
  v20 = *a1 + (int)scnprintf(v18, v19, "\n\techo 1048577-1048580>synx_table");
  *a1 = v20;
  v21 = *a2 - v20;
  v22 = 8 * v21;
  if ( (unsigned __int64)(8 * v21 - 52) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v20 = *a1 + (int)scnprintf(v20, v21, "\n\tFor single handle : echo \"1048577\">synx_table");
    *a1 = v20;
    v21 = *a2 - v20;
    v22 = 8 * v21;
  }
  if ( (unsigned __int64)(v22 - 68) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v20 = *a1 + (int)scnprintf(v20, v21, "\n\tHandle range can be set in hexadecimal values as shown below:");
    *a1 = v20;
    v21 = *a2 - v20;
  }
  v23 = *a1 + (int)scnprintf(v20, v21, "\n\techo 0x100001-10000f>synx_table");
  *a1 = v23;
  v24 = *a1 + (int)scnprintf(v23, *a2 - v23, "\n\tSingle handle : echo 0x100001>synx_table");
  *a1 = v24;
  v25 = *a2 - v24;
  if ( (v25 & 0x1FFFFFFFFFFFFFFFLL) != 6 )
  {
    v24 = *a1 + (int)scnprintf(v24, v25, "\n\n\tTo print info on console : cat synx_table");
    *a1 = v24;
    v25 = *a2 - v24;
  }
  v26 = *a1 + (int)scnprintf(v24, v25, "\n\n\tHandle states :");
  *a1 = v26;
  v27 = *a1 + (int)scnprintf(v26, *a2 - v26, "\n\tACT : SYNX_STATE_ACTIVE");
  *a1 = v27;
  v28 = *a1 + (int)scnprintf(v27, *a2 - v27, "\n\tINV : SYNX_STATE_INVALID");
  *a1 = v28;
  v29 = *a1 + (int)scnprintf(v28, *a2 - v28, "\n\tERR : SYNX_STATE_SIGNALED_ERROR");
  *a1 = v29;
  v30 = *a1 + (int)scnprintf(v29, *a2 - v29, "\n\tSUC : SYNX_STATE_SIGNALED_SUCCESS");
  *a1 = v30;
  v31 = *a2 - v30;
  if ( (unsigned __int64)(8 * v31 - 42) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v30 = *a1 + (int)scnprintf(v30, v31, "\n\tCAN : SYNX_STATE_SIGNALED_CANCELLED");
    *a1 = v30;
    v31 = *a2 - v30;
  }
  if ( (v31 & 0x1FFFFFFFFFFFFFFFLL) == 5
    || (v30 = *a1 + (int)scnprintf(v30, v31, "\n\tEXT : SYNX_STATE_SIGNALED_EXTERNAL"),
        *a1 = v30,
        v31 = *a2 - v30,
        (v31 & 0x1FFFFFFFFFFFFFFFLL) != 4) )
  {
    v30 = *a1 + (int)scnprintf(v30, v31, "\n\tSSR : SYNX_STATE_SIGNALED_SSR\n");
    *a1 = v30;
    v31 = *a2 - v30;
  }
  if ( (unsigned __int64)(8 * v31 - 26) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v30 = *a1 + (int)scnprintf(v30, v31, "\n\tCUS : CUSTOM SIGNAL");
    *a1 = v30;
    v31 = *a2 - v30;
  }
  v32 = *a1 + (int)scnprintf(v30, v31, "\n\t??? : UNKNOWN / UNDEFINED");
  *a1 = v32;
  v33 = *a1 + (int)scnprintf(v32, *a2 - v32, "\n\n\tAdditional information:");
  *a1 = v33;
  v34 = *a2 - v33;
  v35 = 8 * v34;
  if ( (unsigned __int64)(8 * v34 - 67) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v33 = *a1 + (int)scnprintf(v33, v34, "\n\tNo need to set handle ID range and column or table selection");
    *a1 = v33;
    v34 = *a2 - v33;
    v35 = 8 * v34;
  }
  if ( (unsigned __int64)(v35 - 44) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v33 = *a1 + (int)scnprintf(v33, v34, "\tvalues again if once it is already set");
    *a1 = v33;
    v34 = *a2 - v33;
    v35 = 8 * v34;
  }
  if ( (unsigned __int64)(v35 - 66) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v33 = *a1 + (int)scnprintf(v33, v34, "\n\tSimply using cat synx_table command user can print the data");
    *a1 = v33;
    v34 = *a2 - v33;
  }
  if ( (v34 & 0x1FFFFFFFFFFFFFFFLL) != 5 )
  {
    v33 = *a1 + (int)scnprintf(v33, v34, "\tfor same table with same set of columns");
    *a1 = v33;
    v34 = *a2 - v33;
  }
  if ( (unsigned __int64)(8 * v34 - 34) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v33 = *a1 + (int)scnprintf(v33, v34, "\n\tTo print all tables and all");
    *a1 = v33;
    v34 = *a2 - v33;
  }
  v36 = *a1 + (int)scnprintf(v33, v34, "columns set column level value to 0x1fffff");
  *a1 = v36;
  result = scnprintf(v36, *a2 - v36, "\n\tCurrently we do not support CSL fence\n\n");
  *a1 += (int)result;
  return result;
}
