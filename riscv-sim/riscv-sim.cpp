#include "PCH.h"

namespace riscv
{
	typedef uint8_t byte;

	struct context_t
	{};

	namespace instruction
	{
		class base
		{
		public:
//			virtual ~base() {}
		};

		namespace rv32
		{
			namespace format
			{
				template <typename bitfield_t>
				class item
				{
				public:
					typedef bitfield_t bitfield;
					typedef typename bitfield_t::base_type base_type;

					union data_t
					{
						base_type	raw;
						bitfield_t	field;

						data_t() {}
						data_t( const base_type raw): raw( raw) {}
						data_t( const bitfield_t& field): field( field) {}

						bool operator == ( const data_t& item) const { return raw == item.raw; }
						bool operator != ( const data_t& item) const { return raw == item.raw; }
					};

					data_t data;

					item() {}

					item( const base_type raw): data( raw) {}
					item( const bitfield_t& item): data( item) {}

					uint16_t opcode() const { return data.field.opcode; }
					base_type raw() const { return data.raw; }

					operator base_type() const { return data.raw; }

					const bitfield_t& operator () () const { return data.field; }
					bitfield_t& operator () () { return data.field; }

					bool operator == ( const data_t& item) const { return data == item.data; }
					bool operator != ( const data_t& item) const { return data != item.data; }

					void operator = ( const base_type value)	{ data.raw = value; }
					void operator = ( const bitfield_t& item)	{ data.field = item; }
				};

				namespace base
				{
					namespace bitfield
					{
						template <typename T, const byte op_size, const byte rd_size, const byte funct_a_size, const byte rs1_size, const byte rs2_size, const byte funct_b_size>
						struct r
						{
							typedef T base_type;

							T opcode	: op_size;
							T rd		: rd_size;
							T funct_a	: funct_a_size;
							T rs1		: rs1_size;
							T rs2		: rs2_size;
							T funct_b	: funct_b_size;

							r() {}

							template <typename opcode_t>
							r( const opcode_t opcode): opcode( opcode) {}

							template <typename opcode_t, typename rd_t, typename funct_a_t, typename rs1_t, typename rs2_t, typename funct_b_t> 
							r( const opcode_t opcode, const rd_t rd, const funct_a_t funct_a, const rs1_t rs1, const rs2_t rs2, const funct_b_t funct_b): 
								opcode( opcode),
								rd( rd),
								funct_a( funct_a),
								rs1( rs1),
								rs2( rs2),
								funct_b( funct_b)
							{}
						};

						template <typename T, const byte op_size, const byte rd_size, const byte funct_a_size, const byte rs1_size, const byte imm_size>
						struct i
						{
							typedef T base_type;

							T opcode	: op_size;
							T rd		: rd_size;
							T funct_a	: funct_a_size;
							T rs1		: rs1_size;
							T imm		: imm_size;

							i() {}

							template <typename opcode_t>
							i( const opcode_t opcode): opcode( opcode) {}

							template <typename opcode_t, typename rd_t, typename funct_a_t, typename rs1_t, typename imm_t> 
							i( const opcode_t opcode, const rd_t rd, const funct_a_t funct_a, const rs1_t rs1, const imm_t imm): 
								opcode( opcode),
								rd( rd),
								funct_a( funct_a),
								rs1( rs1),
								imm( imm)
							{}
						};

						template <typename T, const byte op_size, const byte rd_size, const byte funct_a_size, const byte rs1_size, const byte rs2_size, const byte imm_size>
						struct s
						{
							typedef T base_type;

							T opcode	: op_size;
							T rd		: rd_size;
							T funct_a	: funct_a_size;
							T rs1		: rs1_size;
							T rs2		: rs2_size;
							T imm		: imm_size;

							s() {}

							template <typename opcode_t>
							s( const opcode_t opcode): opcode( opcode) {}

							template <typename opcode_t, typename rd_t, typename funct_a_t, typename rs1_t, typename rs2_t, typename imm_t> 
							s( const opcode_t opcode, const rd_t rd, const funct_a_t funct_a, const rs1_t rs1, const rs2_t rs2, const imm_t imm): 
								opcode( opcode),
								rd( rd),
								funct_a( funct_a),
								rs1( rs1),
								rs2( rs2),
								imm( imm)
							{}
						};

						template <typename T, const byte op_size, const byte rd_size, const byte imm_size>
						struct u
						{
							typedef T base_type;

							T opcode	: op_size;
							T rd		: rd_size;
							T imm		: imm_size;

							u() {}

							template <typename opcode_t>
							u( const opcode_t opcode): opcode( opcode) {}

							template <typename opcode_t, typename rd_t, typename imm_t> 
							u( const opcode_t opcode, const rd_t rd, const imm_t imm): 
								opcode( opcode),
								rd( rd),
								imm( imm)
							{}
						};
					}

					typedef bitfield::r<uint32_t, 7, 5,  3, 5,  5, 7>	r_bf;
					typedef bitfield::i<uint32_t, 7, 5,  3, 5, 12>		i_bf;
					typedef bitfield::s<uint32_t, 7, 5,  3, 5,  5, 7>	s_bf;
					typedef bitfield::u<uint32_t, 7, 5, 20>				u_bf;

					typedef item<r_bf> r;
					typedef item<i_bf> i;
					typedef item<s_bf> s;
					typedef item<u_bf> u;
				}

				namespace immediate
				{
					namespace bitfield
					{
						template <typename T, const byte op_size, const byte rd_size, const byte funct_size, const byte rs1_size, const byte imm_a_size, const byte imm_b_size, const byte imm_c_size, const byte imm_d_size>
						struct i
						{
							typedef T base_type;

							T opcode	: op_size;
							T rd		: rd_size;
							T funct		: funct_size;
							T rs1		: rs1_size;
							T imm_a		: imm_a_size;
							T imm_b		: imm_b_size;
							T imm_c		: imm_c_size;
							T imm_d		: imm_d_size;

							i() {}

							template <typename opcode_t>
							i( const opcode_t opcode): opcode( opcode) {}

							template <typename opcode_t, typename rd_t, typename funct_t, typename rs1_t, typename imm_a_t, typename imm_b_t, typename imm_c_t, typename imm_d_t> 
							i( const opcode_t opcode, const rd_t rd, const funct_t funct, const rs1_t rs1, const imm_a_t imm_a, const imm_b_t imm_b, const imm_c_t imm_c, const imm_d_t imm_d): 
								opcode( opcode),
								rd( rd),
								funct( funct),
								rs1( rs1),
								imm_a( imm_a),
								imm_b( imm_b),
								imm_c( imm_c),
								imm_d( imm_d)
							{}
						};

						template <typename T, const byte op_size, const byte imm_a_size, const byte imm_b_size, const byte funct_size, const byte rs1_size, const byte rs2_size, 
									const byte imm_c_size, const byte imm_d_size>
						struct s
						{
						public:
							typedef T base_type;

							T opcode	: op_size;
							T imm_a		: imm_a_size;
							T imm_b		: imm_b_size;
							T funct		: funct_size;
							T rs1		: rs1_size;
							T rs2		: rs2_size;
							T imm_c		: imm_c_size;
							T imm_d		: imm_d_size;

							s() {}

							template <typename opcode_t>
							s( const opcode_t opcode): opcode( opcode) {}

							template <typename opcode_t, typename imm_a_t, typename imm_b_t, typename funct_t, typename rs1_t, typename imm_c_t, typename imm_d_t> 
							s( const opcode_t opcode, const imm_a_t imm_a, const imm_b_t imm_b, const funct_t funct, const rs1_t rs1, const imm_c_t imm_c, const imm_d_t imm_d): 
								opcode( opcode),
								rd( rd),
								funct( funct),
								rs1( rs1),
								imm_a( imm_a),
								imm_b( imm_b),
								imm_c( imm_c),
								imm_d( imm_d)
							{}
						};

						template <typename T, const byte op_size, const byte imm_d_size, const byte imm_a_size, const byte funct_size, const byte rs1_size, const byte rs2_size, 
									const byte imm_b_size, const byte imm_c_size>
						struct sb
						{
							typedef T base_type;

							T opcode	: op_size;
							T imm_d		: imm_d_size;
							T imm_a		: imm_a_size;
							T funct		: funct_size;
							T rs1		: rs1_size;
							T rs2		: rs2_size;
							T imm_b		: imm_b_size;
							T imm_c		: imm_c_size;

							sb() {}

							template <typename opcode_t>
							sb( const opcode_t opcode): opcode( opcode) {}

							template <typename opcode_t, typename imm_d_t, typename imm_a_t, typename funct_t, typename rs1_t, typename rs2_t, typename imm_b_t, typename imm_c_t> 
							sb( const opcode_t opcode, const imm_d_t imm_d, const imm_a_t imm_a, const funct_t funct, const rs1_t rs1, const rs2_t rs2, const imm_b_t imm_b, const imm_c_t imm_c):
								opcode( opcode),
								imm_d( imm_d),
								imm_a( imm_a),
								funct( funct),
								rs1( rs1),
								rs2( rs2),
								imm_b( imm_b),
								imm_c( imm_c)
							{}
						};

						template <typename T, const byte op_size, const byte rd_size, const byte imm_a_size, const byte imm_b_size, const byte imm_c_size, const byte imm_d_size>
						struct u
						{
							typedef T base_type;

							T opcode	: op_size;
							T rd		: rd_size;
							T imm_a		: imm_a_size;
							T imm_b		: imm_b_size;
							T imm_c		: imm_c_size;
							T imm_d		: imm_d_size;

							u() {}

							template <typename opcode_t>
							u( const opcode_t opcode): opcode( opcode) {}

							template <typename opcode_t, typename rd_t, typename imm_a_t, typename imm_b_t, typename imm_c_t, typename imm_d_t> 
							u( const opcode_t opcode, const rd_t rd, const imm_a_t imm_a, const imm_b_t imm_b, const imm_c_t imm_c, const imm_d_t imm_d): 
								opcode( opcode),
								rd( rd),
								imm_a( imm_a),
								imm_b( imm_b),
								imm_c( imm_c),
								imm_d( imm_d)
							{}
						};

						template <typename T, const byte op_size, const byte rd_size, const byte imm_d_size, const byte imm_e_size, const byte imm_c_size, 
									const byte imm_a_size, const byte imm_b_size, const byte imm_f_size>
						struct uj
						{
							typedef T base_type;

							T opcode	: op_size;
							T rd		: rd_size;
							T imm_d		: imm_d_size;
							T imm_e		: imm_e_size;
							T imm_c		: imm_c_size;
							T imm_a		: imm_a_size;
							T imm_b		: imm_b_size;
							T imm_f		: imm_f_size;

							uj() {}

							template <typename opcode_t>
							uj( const opcode_t opcode): opcode( opcode) {}

							template <typename opcode_t, typename rd_t, typename imm_d_t, typename imm_e_t, typename imm_c_t, typename imm_a_t, typename imm_b_t, typename imm_f_t> 
							uj( const opcode_t opcode, const rd_t rd, const imm_d_t imm_d, const imm_e_t imm_e, const imm_c_t imm_c, const imm_a_t imm_a, const imm_b_t imm_b, const imm_f_t imm_f): 
								opcode( opcode),
								rd( rd),
								imm_d( imm_d),
								imm_e( imm_e),
								imm_c( imm_c),
								imm_a( imm_a),
								imm_b( imm_b),
								imm_f( imm_f)
							{}
						};
					}

					typedef bitfield::i<uint32_t,	7, 5, 3, 5,  1, 4, 6, 1>	i_bf;
					typedef bitfield::s<uint32_t,	7, 1, 4, 3,  5, 5, 6, 1>	s_bf;
					typedef bitfield::sb<uint32_t,	7, 1, 4, 3,  5, 5, 6, 1>	sb_bf;
					typedef bitfield::u<uint32_t,	7, 5, 3, 5, 11, 1>			u_bf;
					typedef bitfield::uj<uint32_t,	7, 5, 3, 5,  1, 4, 6, 1>	uj_bf;

					typedef item<i_bf>	i;
					typedef item<s_bf>	s;
					typedef item<sb_bf> sb;
					typedef item<u_bf>	u;
					typedef item<uj_bf>	uj;
				}
			}

			namespace field
			{
				namespace funct3
				{
					enum item
					{
						add,
						addi,
						addiw,
						and,
						andi,
						eq	= 0b000,
						ne	= 0b001,
						lt	= 0b100,
						ge	= 0b101,
						ltu	= 0b110,
						geu	= 0b111,
						or,
						ori,
						sll,
						slli,
						slliw,
						slt,
						slti,
						sltiu,
						sltu,
						sra,
						srai,
						sraiw,
						srl,
						srli,
						srliw,
						srlli,
						sub,
						xor,
						xori,
						mul,
						mulh,
						mulhs,
						mulhsu,
						mulw,
						div,
						divu,
						divw,
						divuw,
						rem,
						remu,
						remw,
						remuw,
						csrrw,
						csrrs,
						csrrc,
						csrrwi,
						csrrsi,
						csrrci,
					};
				}

				namespace funct5
				{
					enum item
					{
						fadd,
						fsub,
						fmul,
						fdiv,
						fmin_max,
						fsqrt,
						fcvt,
						fsgnj,
						fmv,
						fmvx,
						fcmp,
					};
				}

				namespace funct12
				{
					enum item
					{
						muldiv,
						scall,
						sbreak,
					};
				}

				namespace csr
				{
					enum item
					{
						rdcycle,
						rdcycle_h,
						rdtime,
						rdtime_h,
						rdinstret,
						rdinstret_h,
					};
				}

				namespace rm
				{
					enum item
					{
						rm_,
						eq,
						lt,
						le,
						min_max,
						j,
						jn,
						jx,
					};
				}

				namespace rd_bit
				{
					enum item
					{
						neg_inf,
						neg_normal_no,
						neg_subnormal_no,
						neg_0,
						pos_0,
						pos_normal_no,
						pos_subnormal_no,
						pos_inf,
						signaling_nan,
						quiet_nan,
					};
				}

				enum null_val : byte
				{
					null_rd = 0,
					null_rs1 = 0,
					null_rs2 = 0,
					null_imm = 0,
					null_imm_a = 0,
					null_imm_b = 0,
					null_imm_c = 0,
					null_imm_d = 0,
					null_imm_e = 0,
				};

				namespace opcode
				{
					enum item
					{
						c_load		= 0b0000011,
						lb			= c_load,
						lbu			= c_load,
						ld			= c_load,
						lh			= c_load,
						lhu			= c_load,
						lw			= c_load,
						lwu			= c_load,

						c_fload		= 0b0000111,
						fld			= c_fload,
						flw			= c_fload,

						c_fence		= 0b0001111,
						fence		= c_fence,
						fence_i		= c_fence,

						c_integer1	= 0b0010011,
						addi		= c_integer1,
						andi		= c_integer1,
						ori			= c_integer1,
						slli		= c_integer1,
						slti		= c_integer1,
						sltiu		= c_integer1,
						srai		= c_integer1,
						srli		= c_integer1,
						xori		= c_integer1,

						auipc		= 0b0010111,

						c_winteger	= 0b0011011,
						addiw		= c_winteger,
						slliw		= c_winteger,
						sraiw		= c_winteger,
						srliw		= c_winteger,

						c_store		= 0b0100011,
						sb			= c_store,
						sd			= c_store,
						sh			= c_store,
						sw			= c_store,

						c_amo		= 0b0100111,
						fsd			= c_amo,
						fsw			= c_amo,
						amoadd_d	= c_amo,
						amoadd_w	= c_amo,
						amoand_d	= c_amo,
						amoand_w	= c_amo,
						amomax_d	= c_amo,
						amomax_w	= c_amo,
						amomaxu_d	= c_amo,
						amomaxu_w	= c_amo,
						amomin_d	= c_amo,
						amomin_w	= c_amo,
						amominu_d	= c_amo,
						amominu_w	= c_amo,
						amoor_d		= c_amo,
						amoor_w		= c_amo,
						amoswap_d	= c_amo,
						amoswap_w	= c_amo,
						amoxor_d	= c_amo,
						amoxor_w	= c_amo,
						lr_d		= c_amo,
						lr_w		= c_amo,
						sc_d		= c_amo,
						sc_w		= c_amo,

						c_integer2  = 0b0110011,
						add			= c_integer2,
						and			= c_integer2,
						div			= c_integer2,
						divu		= c_integer2,
						mul			= c_integer2,
						mulh		= c_integer2,
						mulhsu		= c_integer2,
						mulhu		= c_integer2,
						or			= c_integer2,
						rem			= c_integer2,
						remu		= c_integer2,
						sll			= c_integer2,
						slt			= c_integer2,
						sltu		= c_integer2,
						sra			= c_integer2,
						srl			= c_integer2,
						sub			= c_integer2,
						xor			= c_integer2,
						lui			= c_integer2,
						addw		= c_integer2,
						divuw		= c_integer2,
						divw		= c_integer2,
						mulw		= c_integer2,
						remuw		= c_integer2,
						remw		= c_integer2,
						sllw		= c_integer2,
						sraw		= c_integer2,
						srlw		= c_integer2,
						subw		= c_integer2,

						c_fmadd		= 0b1000011,	
						fmadd_d		= c_fmadd,
						fmadd_s		= c_fmadd,

						c_fmsub		= 0b1000111,
						fmsub_d		= c_fmsub,
						fmsub_s		= c_fmsub,

						c_fnmsub	= 0b1001011,
						fnmsub_d	= c_fnmsub,
						fnmsub_s	= c_fnmsub,

						c_fnmadd	= 0b1001111,
						fnmadd_d	= c_fnmadd,
						fnmadd_s	= c_fnmadd,

						c_float		= 0b1010011,
						fadd_d		= c_float,
						fadd_s		= c_float,
						fclass_d	= c_float,
						fclass_s	= c_float,
						fcvt_d_l	= c_float,
						fcvt_d_lu	= c_float,
						fcvt_d_s	= c_float,
						fcvt_d_w	= c_float,
						fcvt_d_wu	= c_float,
						fcvt_l_d	= c_float,
						fcvt_l_s	= c_float,
						fcvt_lu_d	= c_float,
						fcvt_lu_s	= c_float,
						fcvt_s_d	= c_float,
						fcvt_s_l	= c_float,
						fcvt_s_lu	= c_float,
						fcvt_s_w	= c_float,
						fcvt_s_wu	= c_float,
						fcvt_w_d	= c_float,
						fcvt_w_s	= c_float,
						fcvt_wu_d	= c_float,
						fcvt_wu_s	= c_float,
						fdiv_d		= c_float,
						fdiv_s		= c_float,
						feq_d		= c_float,
						feq_s		= c_float,
						fle_d		= c_float,
						fle_s		= c_float,
						flt_d		= c_float,
						flt_s		= c_float,
						fmax_d		= c_float,
						fmax_s		= c_float,
						fmin_d		= c_float,
						fmin_s		= c_float,
						fmul_d		= c_float,
						fmul_s		= c_float,
						fmv_d_x		= c_float,
						fmv_s_x		= c_float,
						fmv_x_d		= c_float,
						fmv_x_s		= c_float,
						fsgnj_d		= c_float,
						fsgnj_s		= c_float,
						fsgnjn_d	= c_float,
						fsgnjn_s	= c_float,
						fsgnjx_d	= c_float,
						fsgnjx_s	= c_float,
						fsqrt_d		= c_float,
						fsqrt_s		= c_float,
						fsub_d		= c_float,
						fsub_s		= c_float,

						c_branch	= 0b1100011,
						beq			= c_branch,
						bge			= c_branch,
						bgeu		= c_branch,
						blt			= c_branch,
						bltu		= c_branch,
						bne			= c_branch,

						c_jump		= 0b1100111,
						jalr		= c_jump,
						jal			= c_jump,

						c_extra		= 0b1110011,
						frcsr		= c_extra,
						frflags		= c_extra,
						frrm		= c_extra,
						fscsr		= c_extra,
						fsflags		= c_extra,
						fsflagsi	= c_extra,
						fsrm		= c_extra,
						fsrmi		= c_extra,
						rdcycle		= c_extra,
						rdcycleh	= c_extra,
						rdinstret	= c_extra,
						rdinstreth	= c_extra,
						rdtime		= c_extra,
						rdtimeh		= c_extra,
						sbreak		= c_extra,
						scall		= c_extra,
					};
				}
			}

			class auipc: public format::base::u
			{
			public:
				typedef format::base::u super;
				auipc(): super( bitfield( field::opcode::auipc)) {}
			};

			namespace load
			{
				class lui: public format::base::u
				{
				public:
					typedef format::base::u super;
					lui(): super( bitfield( field::opcode::lui)) {}
				};
			}

			namespace store
			{
			}

			namespace jump
			{
				class jal: public format::base::u
				{
				public:
					jal(): format::base::u( bitfield( field::opcode::jal)) {}
				};

				class jalr: public format::base::i
				{
				public:
					jalr(): format::base::i( bitfield( field::opcode::jalr, field::null_rd, field::funct3::eq, field::null_rs1, field::null_imm)) {}
				};
			}

			namespace branch
			{
				typedef format::immediate::sb sb_imm;

				class beq: public sb_imm
				{
				public:
					beq(): sb_imm( bitfield( field::opcode::beq, field::null_imm_d, field::null_imm_a, field::funct3::eq, field::null_rs1, field::null_rs2, field::null_imm_b, field::null_imm_c)) {}
				};

				class bne: public sb_imm
				{
				public:
					bne(): sb_imm( bitfield( field::opcode::bne, field::null_imm_d, field::null_imm_a, field::funct3::ne, field::null_rs1, field::null_rs2, field::null_imm_b, field::null_imm_c)) {}
				};

				class blt: public sb_imm
				{
				public:
					blt(): sb_imm( bitfield( field::opcode::blt, field::null_imm_d, field::null_imm_a, field::funct3::lt, field::null_rs1, field::null_rs2, field::null_imm_b, field::null_imm_c)) {}
				};

				class bltu: public sb_imm
				{
				public:
					bltu(): sb_imm( bitfield( field::opcode::bge, field::null_imm_d, field::null_imm_a, field::funct3::ltu, field::null_rs1, field::null_rs2, field::null_imm_b, field::null_imm_c)) {}
				};

				class bge: public sb_imm
				{
				public:
					bge(): sb_imm( bitfield( field::opcode::bge, field::null_imm_d, field::null_imm_a, field::funct3::ge, field::null_rs1, field::null_rs2, field::null_imm_b, field::null_imm_c)) {}
				};

				class bgeu: public sb_imm
				{
				public:
					bgeu(): sb_imm( bitfield( field::opcode::bgeu, field::null_imm_d, field::null_imm_a, field::funct3::geu, field::null_rs1, field::null_rs2, field::null_imm_b, field::null_imm_c)) {}
				};
			}
		}

		class decoder
		{
		};

		class queue
		{
		};
	}

	namespace register_
	{
		class base
		{
		public:
			virtual ~base() {}
		};

		template <typename T>
		class r: public base
		{
		};

		typedef r<uint16_t> r16;
		typedef r<uint32_t> r32;
		typedef r<uint64_t> r64;

		class r128: public base
		{
		public:
			virtual ~r128() {}
		};

		namespace vector
		{
			class base
			{
			public:
				virtual ~base() {}
			};

			template <typename T, const uint8_t size>
			class r: public base
			{
			};

			template <const uint8_t size>
			using r16 = r<uint16_t, size>;

			template <const uint8_t size>
			using r32 = r<uint32_t, size>;

			template <const uint8_t size>
			using r64 = r<uint64_t, size>;
		}
	}

	namespace unit
	{
		class base
		{
		public:
			virtual ~base() {}
		};

		// arithmetic logic unit
		namespace alu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// fixed-point execution unit
		namespace fxu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// fixed-point execution unitfixed-point execution unit
		namespace fpu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// address generation unit
		namespace agu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		namespace branch_prediction
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// memory management unit
		namespace mmu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// translation lookaside buffer
		namespace tlb
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// memory interface unit
		namespace miu
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		// memory order buffer
		namespace mob
		{
			class base: public unit::base
			{
			public:
				virtual ~base() {}
			};
		}

		namespace cache
		{
			class base
			{
			public:
				virtual ~base() {}
			};

			namespace instruction
			{
				class base
				{
				public:
					virtual ~base() {}
				};
			}

			namespace data
			{
				class base
				{
				public:
					virtual ~base() {}
				};
			}

			namespace unified
			{
				class base
				{
				public:
					virtual ~base() {}
				};
			}
		}

		namespace scheduler
		{
			class base
			{
			public:
				virtual ~base() {}
			};
		}

		namespace simd
		{
			class base: public unit::base
			{
			public:
			};

			// SIMD ALU
			class alu: public base
			{
			public:
				virtual ~alu() {}
			};

			// SIMD FPU
			class fpu: public base
			{
			public:
				virtual ~fpu() {}
			};
		}
	}

	namespace memory
	{
		class base
		{
		public:
			virtual ~base() {}
		};
	}

	namespace cpu
	{
		class base
		{
		public:
			virtual ~base() {}
		};

		namespace scalar
		{
			class base: public cpu::base
			{
			public:
				virtual ~base() {}
			};

			class s1: public base
			{
			public:
			};
		}

		namespace superscalar
		{
			class base: public cpu::base
			{
			public:
				virtual ~base() {}
			};

			class s1: public base
			{
			public:
			};
		}
	}

	namespace simulator
	{
		class base
		{
		public:
			virtual ~base() {}
		};

		namespace scalar
		{
			template <typename cpu_t, const uint8_t cpu_count>
			class t1: public base
			{
			};

			template <const uint8_t size>
			using s1 = t1<cpu::scalar::s1, size>;

			typedef s1<1> single_core1;
			typedef s1<2> dual_core1;
			typedef s1<4> quad_core1;
		}

		namespace superscalar
		{
			template <typename cpu_t, const uint8_t cpu_count>
			class t1: public base
			{
			};

			template <const uint8_t size>
			using s1 = t1<cpu::superscalar::s1, size>;

			typedef s1<1> single_core1;
			typedef s1<2> dual_core1;
			typedef s1<4> quad_core1;
			typedef s1<8> octa_core1;
		}
	}
}

int main()
{
	using namespace riscv;
	simulator::superscalar::quad_core1 simulator;

	instruction::rv32::load::lui lui;
	lui().rd = 5;
	auto op = lui.opcode();

	return 0;
}
