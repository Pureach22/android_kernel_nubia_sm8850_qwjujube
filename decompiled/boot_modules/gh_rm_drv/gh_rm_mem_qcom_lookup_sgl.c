unsigned __int64 __fastcall gh_rm_mem_qcom_lookup_sgl(
        unsigned __int8 a1,
        int a2,
        unsigned int *a3,
        unsigned int *a4,
        _WORD *a5,
        _DWORD *a6)
{
  unsigned int v6; // w20
  unsigned __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v13; // x22
  unsigned __int64 v14; // x20
  unsigned __int64 v15; // x19
  unsigned int v16; // w0
  unsigned int v17; // w20
  __int64 v18; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF

  v6 = a1;
  result = 4294967274LL;
  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( v6 <= 1 )
  {
    if ( a3 )
    {
      if ( a4 )
      {
        v8 = *a3;
        if ( (_DWORD)v8 )
        {
          if ( a6 )
          {
            v9 = *a4;
            if ( (_DWORD)v9 )
            {
              if ( a5 )
              {
                v10 = (unsigned __int16)*a5;
                if ( !*a5 )
                  goto LABEL_22;
              }
              else
              {
                v10 = 0;
              }
              v18 = 0;
              v19[0] = 0;
              v13 = 4 * (v10 + v8) + 16 * v9;
              result = _kmalloc_noprof(v13 + 20, 3520);
              if ( result )
              {
                if ( result < 0xFFFFFFFFFFFFF001LL )
                {
                  *(_BYTE *)result = v6;
                  v14 = result;
                  *(_DWORD *)(result + 4) = a2;
                  gh_rm_populate_mem_request();
                  v15 = v14;
                  v16 = gunyah_rm_call(rm, 1358954522, v14, v13 + 20, v19, &v18);
                  if ( v16 )
                  {
                    v17 = v16;
                    printk(&unk_13114, "gh_rm_mem_qcom_lookup_sgl");
                  }
                  else if ( v18 == 4 )
                  {
                    v17 = 0;
                    *a6 = *(_DWORD *)v19[0];
                  }
                  else
                  {
                    printk(&unk_138D7, "gh_rm_mem_qcom_lookup_sgl");
                    if ( v18 )
                      kfree(v19[0]);
                    v17 = -22;
                  }
                  kfree(v15);
                  result = v17;
                }
              }
              else
              {
                result = -12;
              }
            }
          }
        }
      }
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
