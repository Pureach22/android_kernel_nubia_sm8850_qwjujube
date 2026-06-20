__int64 __fastcall msm_buffer_size_iris4(__int64 a1, unsigned int a2)
{
  __int64 v2; // x4
  int *v4; // x8
  unsigned int v5; // w20
  __int64 v6; // x9
  __int64 result; // x0
  void *v8; // x0
  __int64 v9; // x2
  __int64 (*v10)(void); // x8
  unsigned int v11; // w21
  __int64 v12; // x0

  v2 = *(unsigned int *)(a1 + 308);
  if ( (_DWORD)v2 == 2 )
  {
    v4 = &msm_buffer_size_iris4_dec_buf_type_handle;
  }
  else
  {
    if ( (_DWORD)v2 != 1 )
    {
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 0;
      v8 = &unk_92A7E;
      v9 = a1 + 340;
      goto LABEL_21;
    }
    v4 = &msm_buffer_size_iris4_enc_buf_type_handle;
  }
  if ( *v4 != a2 )
  {
    if ( v4[4] == a2 )
    {
      v5 = a2;
      v6 = 1;
      goto LABEL_32;
    }
    if ( v4[8] == a2 )
    {
      v5 = a2;
      v6 = 2;
      goto LABEL_32;
    }
    if ( v4[12] == a2 )
    {
      v5 = a2;
      v6 = 3;
      goto LABEL_32;
    }
    if ( v4[16] == a2 )
    {
      v5 = a2;
      v6 = 4;
      goto LABEL_32;
    }
    if ( v4[20] == a2 )
    {
      v5 = a2;
      v6 = 5;
      goto LABEL_32;
    }
    if ( v4[24] == a2 )
    {
      v5 = a2;
      v6 = 6;
      goto LABEL_32;
    }
    if ( v4[28] == a2 )
    {
      v5 = a2;
      v6 = 7;
      goto LABEL_32;
    }
    if ( v4[32] == a2 )
    {
      v5 = a2;
      v6 = 8;
      goto LABEL_32;
    }
    if ( v4[36] == a2 )
    {
      v5 = a2;
      v6 = 9;
      goto LABEL_32;
    }
    if ( v4[40] == a2 )
    {
      v5 = a2;
      v6 = 10;
      goto LABEL_32;
    }
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 0;
    v8 = &unk_83EA3;
    v9 = a1 + 340;
    v2 = a2;
LABEL_21:
    printk(v8, "err ", v9, "msm_buffer_size_iris4", v2);
    return 0;
  }
  v5 = a2;
  v6 = 0;
LABEL_32:
  v10 = *(__int64 (**)(void))&v4[4 * v6 + 2];
  if ( *((_DWORD *)v10 - 1) != 873944275 )
    __break(0x8228u);
  result = v10();
  if ( a1 )
  {
    if ( (msm_vidc_debug & 4) != 0 )
    {
      v11 = result;
      v12 = buf_name(v5);
      printk(&unk_7F656, "low ", a1 + 340, v12, v11);
      return v11;
    }
  }
  return result;
}
