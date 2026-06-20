__int64 __fastcall cqhci_dumpregs(__int64 (__fastcall ***a1)(_QWORD), __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 (__fastcall **v5)(_QWORD); // x19
  __int64 (__fastcall *v7)(_QWORD); // x1
  int v8; // w23
  __int64 (__fastcall *v9)(_QWORD); // x21
  _DWORD *v10; // x8
  unsigned int v11; // w0
  unsigned int v12; // w22
  _DWORD *v13; // x8
  unsigned int v14; // w0
  __int64 v15; // x4
  __int64 (__fastcall *v16)(_QWORD); // x21
  _DWORD *v17; // x8
  unsigned int v18; // w0
  unsigned int v19; // w22
  _DWORD *v20; // x8
  unsigned int v21; // w0
  __int64 v22; // x4
  __int64 (__fastcall *v23)(_QWORD); // x21
  _DWORD *v24; // x8
  unsigned int v25; // w0
  unsigned int v26; // w22
  _DWORD *v27; // x8
  unsigned int v28; // w0
  __int64 v29; // x4
  __int64 (__fastcall *v30)(_QWORD); // x21
  _DWORD *v31; // x8
  unsigned int v32; // w0
  unsigned int v33; // w22
  _DWORD *v34; // x8
  unsigned int v35; // w0
  __int64 v36; // x4
  __int64 (__fastcall *v37)(_QWORD); // x21
  _DWORD *v38; // x8
  unsigned int v39; // w0
  unsigned int v40; // w22
  _DWORD *v41; // x8
  unsigned int v42; // w0
  __int64 v43; // x4
  __int64 (__fastcall *v44)(_QWORD); // x21
  _DWORD *v45; // x8
  unsigned int v46; // w0
  unsigned int v47; // w22
  _DWORD *v48; // x8
  unsigned int v49; // w0
  __int64 v50; // x4
  __int64 (__fastcall *v51)(_QWORD); // x21
  _DWORD *v52; // x8
  unsigned int v53; // w0
  unsigned int v54; // w22
  _DWORD *v55; // x8
  unsigned int v56; // w0
  __int64 v57; // x4
  __int64 (__fastcall *v58)(_QWORD); // x21
  _DWORD *v59; // x8
  unsigned int v60; // w0
  unsigned int v61; // w22
  _DWORD *v62; // x8
  unsigned int v63; // w0
  __int64 v64; // x4
  __int64 (__fastcall *v65)(_QWORD); // x21
  _DWORD *v66; // x8
  unsigned int v67; // w0
  unsigned int v68; // w22
  _DWORD *v69; // x8
  unsigned int v70; // w0
  __int64 v71; // x4
  __int64 (__fastcall *v72)(_QWORD); // x21
  _DWORD *v73; // x8
  unsigned int v74; // w0
  unsigned int v75; // w22
  _DWORD *v76; // x8
  unsigned int v77; // w0
  __int64 v78; // x4
  __int64 (__fastcall *v79)(_QWORD); // x21
  _DWORD *v80; // x8
  unsigned int v81; // w0
  unsigned int v82; // w22
  _DWORD *v83; // x8
  unsigned int v84; // w0
  __int64 v85; // x4
  __int64 (__fastcall *v86)(_QWORD); // x21
  _DWORD *v87; // x8
  __int64 v88; // x1
  unsigned int v89; // w0
  __int64 v90; // x3
  __int64 v91; // x4
  __int64 v92; // x2
  __int64 v93; // x3
  __int64 v94; // x4
  __int64 (__fastcall *v95)(_QWORD); // x8
  __int64 (__fastcall *v97)(_QWORD); // x1

  v5 = a1[2];
  v7 = v5[15];
  if ( !v7 )
    v7 = v5[1];
  v8 = *((unsigned __int8 *)a1 + 62);
  printk(&unk_A1D5, v7, a3, a4, a5);
  v9 = v5[15];
  if ( !v9 )
    v9 = v5[1];
  v10 = (*a1)[2];
  if ( v10 )
  {
    if ( *(v10 - 1) != 1427797680 )
      __break(0x8228u);
    v11 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v10)(a1, 4);
  }
  else
  {
    v11 = readl_relaxed((char *)a1[1] + 4);
  }
  v12 = v11;
  v13 = (*a1)[2];
  if ( v13 )
  {
    if ( *(v13 - 1) != 1427797680 )
      __break(0x8228u);
    v14 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), _QWORD))v13)(a1, 0);
  }
  else
  {
    v14 = readl_relaxed(a1[1]);
  }
  printk(&unk_A138, v9, v12, v14, v15);
  v16 = v5[15];
  if ( !v16 )
    v16 = v5[1];
  v17 = (*a1)[2];
  if ( v17 )
  {
    if ( *(v17 - 1) != 1427797680 )
      __break(0x8228u);
    v18 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v17)(a1, 8);
  }
  else
  {
    v18 = readl_relaxed(a1[1] + 1);
  }
  v19 = v18;
  v20 = (*a1)[2];
  if ( v20 )
  {
    if ( *(v20 - 1) != 1427797680 )
      __break(0x8228u);
    v21 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v20)(a1, 12);
  }
  else
  {
    v21 = readl_relaxed((char *)a1[1] + 12);
  }
  printk(&unk_9BD2, v16, v19, v21, v22);
  v23 = v5[15];
  if ( !v23 )
    v23 = v5[1];
  v24 = (*a1)[2];
  if ( v24 )
  {
    if ( *(v24 - 1) != 1427797680 )
      __break(0x8228u);
    v25 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v24)(a1, 16);
  }
  else
  {
    v25 = readl_relaxed(a1[1] + 2);
  }
  v26 = v25;
  v27 = (*a1)[2];
  if ( v27 )
  {
    if ( *(v27 - 1) != 1427797680 )
      __break(0x8228u);
    v28 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v27)(a1, 20);
  }
  else
  {
    v28 = readl_relaxed((char *)a1[1] + 20);
  }
  printk(&unk_9C38, v23, v26, v28, v29);
  v30 = v5[15];
  if ( !v30 )
    v30 = v5[1];
  v31 = (*a1)[2];
  if ( v31 )
  {
    if ( *(v31 - 1) != 1427797680 )
      __break(0x8228u);
    v32 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v31)(a1, 24);
  }
  else
  {
    v32 = readl_relaxed(a1[1] + 3);
  }
  v33 = v32;
  v34 = (*a1)[2];
  if ( v34 )
  {
    if ( *(v34 - 1) != 1427797680 )
      __break(0x8228u);
    v35 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v34)(a1, 28);
  }
  else
  {
    v35 = readl_relaxed((char *)a1[1] + 28);
  }
  printk(&unk_9C05, v30, v33, v35, v36);
  v37 = v5[15];
  if ( !v37 )
    v37 = v5[1];
  v38 = (*a1)[2];
  if ( v38 )
  {
    if ( *(v38 - 1) != 1427797680 )
      __break(0x8228u);
    v39 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v38)(a1, 32);
  }
  else
  {
    v39 = readl_relaxed(a1[1] + 4);
  }
  v40 = v39;
  v41 = (*a1)[2];
  if ( v41 )
  {
    if ( *(v41 - 1) != 1427797680 )
      __break(0x8228u);
    v42 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v41)(a1, 36);
  }
  else
  {
    v42 = readl_relaxed((char *)a1[1] + 36);
  }
  printk(&unk_9E74, v37, v40, v42, v43);
  v44 = v5[15];
  if ( !v44 )
    v44 = v5[1];
  v45 = (*a1)[2];
  if ( v45 )
  {
    if ( *(v45 - 1) != 1427797680 )
      __break(0x8228u);
    v46 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v45)(a1, 40);
  }
  else
  {
    v46 = readl_relaxed(a1[1] + 5);
  }
  v47 = v46;
  v48 = (*a1)[2];
  if ( v48 )
  {
    if ( *(v48 - 1) != 1427797680 )
      __break(0x8228u);
    v49 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v48)(a1, 44);
  }
  else
  {
    v49 = readl_relaxed((char *)a1[1] + 44);
  }
  printk(&unk_A28E, v44, v47, v49, v50);
  v51 = v5[15];
  if ( !v51 )
    v51 = v5[1];
  v52 = (*a1)[2];
  if ( v52 )
  {
    if ( *(v52 - 1) != 1427797680 )
      __break(0x8228u);
    v53 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v52)(a1, 48);
  }
  else
  {
    v53 = readl_relaxed(a1[1] + 6);
  }
  v54 = v53;
  v55 = (*a1)[2];
  if ( v55 )
  {
    if ( *(v55 - 1) != 1427797680 )
      __break(0x8228u);
    v56 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v55)(a1, 52);
  }
  else
  {
    v56 = readl_relaxed((char *)a1[1] + 52);
  }
  printk(&unk_9F0B, v51, v54, v56, v57);
  v58 = v5[15];
  if ( !v58 )
    v58 = v5[1];
  v59 = (*a1)[2];
  if ( v59 )
  {
    if ( *(v59 - 1) != 1427797680 )
      __break(0x8228u);
    v60 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v59)(a1, 56);
  }
  else
  {
    v60 = readl_relaxed(a1[1] + 7);
  }
  v61 = v60;
  v62 = (*a1)[2];
  if ( v62 )
  {
    if ( *(v62 - 1) != 1427797680 )
      __break(0x8228u);
    v63 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v62)(a1, 64);
  }
  else
  {
    v63 = readl_relaxed(a1[1] + 8);
  }
  printk(&unk_9CAA, v58, v61, v63, v64);
  v65 = v5[15];
  if ( !v65 )
    v65 = v5[1];
  v66 = (*a1)[2];
  if ( v66 )
  {
    if ( *(v66 - 1) != 1427797680 )
      __break(0x8228u);
    v67 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v66)(a1, 68);
  }
  else
  {
    v67 = readl_relaxed((char *)a1[1] + 68);
  }
  v68 = v67;
  v69 = (*a1)[2];
  if ( v69 )
  {
    if ( *(v69 - 1) != 1427797680 )
      __break(0x8228u);
    v70 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v69)(a1, 72);
  }
  else
  {
    v70 = readl_relaxed(a1[1] + 9);
  }
  printk(&unk_9F99, v65, v68, v70, v71);
  v72 = v5[15];
  if ( !v72 )
    v72 = v5[1];
  v73 = (*a1)[2];
  if ( v73 )
  {
    if ( *(v73 - 1) != 1427797680 )
      __break(0x8228u);
    v74 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v73)(a1, 80);
  }
  else
  {
    v74 = readl_relaxed(a1[1] + 10);
  }
  v75 = v74;
  v76 = (*a1)[2];
  if ( v76 )
  {
    if ( *(v76 - 1) != 1427797680 )
      __break(0x8228u);
    v77 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v76)(a1, 84);
  }
  else
  {
    v77 = readl_relaxed((char *)a1[1] + 84);
  }
  printk(&unk_9D94, v72, v75, v77, v78);
  v79 = v5[15];
  if ( !v79 )
    v79 = v5[1];
  v80 = (*a1)[2];
  if ( v80 )
  {
    if ( *(v80 - 1) != 1427797680 )
      __break(0x8228u);
    v81 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v80)(a1, 88);
  }
  else
  {
    v81 = readl_relaxed(a1[1] + 11);
  }
  v82 = v81;
  v83 = (*a1)[2];
  if ( v83 )
  {
    if ( *(v83 - 1) != 1427797680 )
      __break(0x8228u);
    v84 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v83)(a1, 92);
  }
  else
  {
    v84 = readl_relaxed((char *)a1[1] + 92);
  }
  printk(&unk_9D61, v79, v82, v84, v85);
  v86 = v5[15];
  if ( !v86 )
    v86 = v5[1];
  v87 = (*a1)[2];
  if ( v8 )
    v88 = 2560;
  else
    v88 = 256;
  if ( v87 )
  {
    if ( *(v87 - 1) != 1427797680 )
      __break(0x8228u);
    v89 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD), __int64))v87)(a1, v88);
  }
  else
  {
    v89 = readl_relaxed((char *)a1[1] + (unsigned int)v88);
  }
  printk(&unk_A16B, v86, v89, v90, v91);
  v95 = **a1;
  if ( v95 )
  {
    if ( *((_DWORD *)v95 - 1) != -452870896 )
      __break(0x8228u);
    return v95(v5);
  }
  else
  {
    v97 = v5[15];
    if ( !v97 )
      v97 = v5[1];
    return printk(&unk_A2C1, v97, v92, v93, v94);
  }
}
