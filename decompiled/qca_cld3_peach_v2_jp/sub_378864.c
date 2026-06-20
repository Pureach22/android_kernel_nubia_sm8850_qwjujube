// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_378864@<X0>(
        int a1@<W0>,
        int a2@<W1>,
        int a3@<W2>,
        int a4@<W3>,
        int a5@<W4>,
        int a6@<W5>,
        int a7@<W8>)
{
  __int64 v7; // x9
  unsigned int v8; // w10
  int v9; // w11
  int v10; // w12
  __int64 v11; // x13
  int v12; // w14
  int v13; // w15
  int v14; // w16
  int v15; // w17
  __int64 v16; // x19
  char *v17; // x20
  char v18; // w6
  int v19; // t1
  unsigned __int64 v20; // x9
  int v21; // w11
  int v22; // w12
  int v23; // w14
  int v24; // w15
  int v25; // w16
  int v26; // w17
  int v27; // w0
  int v28; // w1
  int v29; // w2
  int v30; // w3
  int v31; // w4
  int v32; // w5
  int v33; // w7
  bool v34; // w6
  unsigned int v35; // w20
  _BYTE v37[87]; // [xsp-57h] [xbp-57h]

  if ( (v16 & 0x1000000000000000LL) == 0 )
    JUMPOUT(0x378868);
  do
  {
    v19 = *v17++;
    v18 = v19;
    if ( v19 < 0 )
    {
      if ( v8 > 0xB )
LABEL_50:
        __break(0x5512u);
      *(_BYTE *)(v11 + v8++) = v18;
    }
    --v7;
  }
  while ( v7 );
  if ( v8 )
  {
    v20 = 0;
    v21 = v9 | 0x80;
    v22 = v10 | 0x80;
    v23 = v12 | 0x80;
    v24 = v13 | 0x80;
    v25 = v14 | 0x80;
    v26 = v15 | 0x80;
    v27 = a1 | 0x80;
    v28 = a2 | 0x80;
    v29 = a3 | 0x80;
    v30 = a4 | 0x80;
    v31 = a5 | 0x80;
    v32 = a6 | 0x80;
    while ( a7 )
    {
      if ( v20 > 0xB )
        goto LABEL_50;
      v33 = (unsigned __int8)v37[v20];
      v34 = v21 == v33;
      if ( a7 != 1 )
      {
        if ( v22 == v33 )
          v34 = 1;
        if ( a7 != 2 )
        {
          if ( v23 == v33 )
            v34 = 1;
          if ( a7 != 3 )
          {
            if ( v24 == v33 )
              v34 = 1;
            if ( a7 != 4 )
            {
              if ( v25 == v33 )
                v34 = 1;
              if ( a7 != 5 )
              {
                if ( v26 == v33 )
                  v34 = 1;
                if ( a7 != 6 )
                {
                  if ( v27 == v33 )
                    v34 = 1;
                  if ( a7 != 7 )
                  {
                    if ( v28 == v33 )
                      v34 = 1;
                    if ( a7 != 8 )
                    {
                      if ( v29 == v33 )
                        v34 = 1;
                      if ( a7 != 9 )
                      {
                        if ( v30 == v33 )
                          v34 = 1;
                        if ( a7 != 10 )
                        {
                          if ( v31 == v33 )
                            v34 = 1;
                          if ( a7 != 11 && v32 == v33 )
                            v34 = 1;
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
      if ( !v34 )
        break;
      if ( v8 == ++v20 )
        goto LABEL_47;
    }
    v35 = 0;
  }
  else
  {
LABEL_47:
    v35 = 1;
  }
  _qdf_mem_free(v16);
  _ReadStatusReg(SP_EL0);
  return v35;
}
